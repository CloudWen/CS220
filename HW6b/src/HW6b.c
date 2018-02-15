/*
 ============================================================================
 Name        : HW6b.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello MPI World in C 
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "mpi.h"


int main(int argc, char* argv[]){
	int  my_rank; /* rank of process */
	int  p;       /* number of processes */
	int source;   /* rank of sender */
	int dest;     /* rank of receiver */
	int tag=0;    /* tag for messages */
	char message[100];        /* storage for message */
	MPI_Status status ;   /* return status for receive */
	
	int local_sum = 0;
	int total_sum = 0;



	int input_array[10] = {1,2,3,4,5,6,7,8,9,10};
	int input_size = 10;


	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p); 
	
	if (my_rank != 0 && my_rank != input_size-1){ /* if I'm not process 0 or last process, receive the sum from last process, add up and send it to the next process*/
		MPI_Recv(&local_sum, 1, MPI_INT, my_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		local_sum += input_array[my_rank];

		MPI_Send(&local_sum, 1, MPI_INT, my_rank+1, 0, MPI_COMM_WORLD);
		printf("my_rank:%d, number:%d, local_sum: %d! \n", my_rank, input_array[my_rank], local_sum);
	}
	else if(my_rank == 0){	/* if I'm process 0, no receive, only add up and send it to the next process */
		local_sum += input_array[my_rank];
		MPI_Send(&local_sum, 1, MPI_INT, my_rank+1, 0, MPI_COMM_WORLD);
		printf("my_rank:%d, number:%d, local_sum: %d! \n", my_rank, input_array[my_rank], local_sum);
	}
	else{	/*	if I'm the last process, receive the sum and store into total_sum and output it.*/
		MPI_Recv(&local_sum, 1, MPI_INT, my_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		local_sum += input_array[my_rank];
		printf("my_rank:%d, number:%d, local_sum: %d! \n", my_rank, input_array[my_rank], local_sum);
		total_sum = local_sum;
		printf("Total: %d\n",total_sum);
		}




	/* shut down MPI */
	MPI_Finalize(); 

	
	return 0;
}



