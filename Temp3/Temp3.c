/*
 ============================================================================
 Name        : Temp3.c
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
	

	int input_size;
	int point;

	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p); 
	
	
	if (my_rank ==0){

		puts("Please enter an even number n for rows and columns of Matrix: ");
		scanf("%d", &input_size);
		point = input_size/p;
		//
		printf("Point:%d", point);

	}

	MPI_Bcast(&input_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&point, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("My rank:%d, input_size: %d\n", my_rank, input_size);

	double local_array[input_size];
	double local_x;

	if(my_rank == 0){
		double matrix[input_size][input_size];
		double vector[input_size];
		for(int i=0; i<input_size; i++){
			for(int j=0; j<input_size; j++){
				printf("Please enter a number for row%d column%d: \n", i,j);
				scanf("%lf", &matrix[i][j]);
			}
		}
		for(int i=0; i<input_size; i++){
			printf("Please enter a number of the vector for column%d: \n",i);
			scanf("%lf", &vector[i]);
		}


		//debug.
		puts("Finish input, now output:");
		puts("Matrix: ");
		for(int i=0; i<input_size; i++){
			for(int j=0; j<input_size; j++){
				printf("%lf ",matrix[i][j]);
			}
			printf("\n");
		}
		puts("Vector:");
		for(int i=0; i<input_size; i++){
			printf("%lf\n",vector[i]);
		}
		puts("End!");



		for(int j=0; j<input_size; j++){
			local_x = vector[j];
			MPI_Send(&local_x, 1, MPI_DOUBLE, j, 0, MPI_COMM_WORLD);
			for(int i=0; i<input_size; i++){
				local_array[i] = matrix[i][j];
			}
			MPI_Send(local_array, input_size, MPI_DOUBLE, j, 0, MPI_COMM_WORLD);
		}

		MPI_Recv(&local_x, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(local_array, input_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);



		for(int i=0; i<input_size; i++){
			printf("MYRANK:%d, LOCAL_ARRAY:%lf, LOCAL_X:%lf \n", my_rank, local_array[i], local_x);
		}
	}
	else{

		MPI_Recv(&local_x, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(local_array, input_size, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);



		for(int i=0; i<input_size; i++){
			printf("MYRANK:%d, LOCAL_ARRAY:%lf, LOCAL_X:%lf \n", my_rank, local_array[i], local_x);
		}
	}

	for(int i=0; i<input_size; i++){
		local_array[i]*=local_x;
	}

	//
	for(int i=0; i<input_size; i++){
		printf("MYRANK:%d, LOCAL_ARRAY:%lf, LOCAL_X:%lf \n", my_rank, local_array[i], local_x);
	}

	double recvbuf;
	int recvcounts[input_size];
	for(int i=0; i<input_size; i++){
		recvcounts[i]=1;
	}
	MPI_Reduce_scatter(local_array, &recvbuf, recvcounts, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

	printf("Process%d: %lf\n", my_rank, recvbuf);
	/* shut down MPI */
	MPI_Finalize(); 
	
	
	return 0;
}
