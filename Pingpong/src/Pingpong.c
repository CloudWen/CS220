/*
 ============================================================================
 Name        : Pingpong.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello MPI World in C 
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int  my_rank; /* rank of process */
	int  p;       /* number of processes */
	int source;   /* rank of sender */
	int dest;     /* rank of receiver */
	int tag=0;    /* tag for messages */
	char message[100];        /* storage for message */
	MPI_Status status ;   /* return status for receive */
	
//	clock_t start_t, end_t;
	double time;
	const int PINGPONG_TIMES = 1048576;


	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p); 

	int pingpong_count = 0;

	time = MPI_Wtime();
//	start_t = clock();
	while(pingpong_count < PINGPONG_TIMES){
		if (my_rank == 0){
			pingpong_count++;
			MPI_Send(&pingpong_count, 1, MPI_INT,
					1, tag, MPI_COMM_WORLD);
		}
		else{
			MPI_Send(&pingpong_count, 1, MPI_INT,
								0, tag, MPI_COMM_WORLD);
			pingpong_count++;
		}
	}
	time = MPI_Wtime()-time;
//	end_t = clock();
	/* shut down MPI */
	MPI_Finalize();

	printf("Total time taken by CPU: %f seconds\n", time);
//	printf("Total time taken by CPU: %f\n", (double)(end_t - start_t)/CLOCKS_PER_SEC );

	return 0;
}
