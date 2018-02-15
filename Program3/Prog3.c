/*
 ============================================================================
 Name        : Prog3.c
 Author      : Pengtao Wen
 Version     :
 Copyright   : Your copyright notice
 Description : Matrix-vector multiplication MPI version in C
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
	int mpoint;

	/* start up MPI */
	
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p); 
	
	/*Get the input size from user, calculate mid point, then Boardcast both of them.*/
	if (my_rank ==0){
		puts("Please enter an even number n for rows and columns of Matrix: ");
		scanf("%d", &input_size);
		mpoint = input_size/p;
	}

	MPI_Bcast(&input_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&mpoint, 1, MPI_INT, 0, MPI_COMM_WORLD);


	double matrix[input_size][input_size];
	double vector[input_size];

	/*Get the input matrix and vector from user, the Boardcast both of them.*/
	if(my_rank == 0){
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
	}
	MPI_Bcast(matrix, input_size*input_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(vector, input_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	double recvbuf[mpoint];
	int recvcounts[input_size];
	for(int i=0; i<input_size/mpoint; i++){
		recvcounts[i]=mpoint;
	}
	double sendbuf[input_size];


	/*Process0 calculate first half matrix*/
	if(my_rank == 0){
		for(int j=0; j<mpoint; j++){
			for(int i=0; i<input_size; i++){
				matrix[i][j]*=vector[j];
				sendbuf[i] += matrix[i][j];
			}
		}
	}
	else{		/*Process1 calculate the other half matrix*/
		for(int j=mpoint; j<input_size; j++){
			for(int i=0; i<input_size; i++){
				matrix[i][j]*=vector[j];
				sendbuf[i] += matrix[i][j];
			}
		}
	}
	MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

	for(int i=0; i<mpoint; i++){
		printf("Process%d result%d: %lf\n", my_rank, i+1, recvbuf[i]);
	}
	/* shut down MPI */
	MPI_Finalize(); 
	
	
	return 0;
}
