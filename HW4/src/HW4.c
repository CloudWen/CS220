/*
 ============================================================================
 Name        : HW4.c
 Author      : Pengtao Wen
 Version     :
 Copyright   : Your copyright notice
 Description : Homework 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define Mx(arg,r,c)((arg).pX[r][c])


struct Matrix{
	int rows;
	int cols;
	double **pX;
};

struct Matrix MatAlloc(int rows, int columns);
void MatPrint(struct Matrix M, char messg[]);
void MatFree(struct Matrix M);
void MatAdd(struct Matrix A, struct Matrix B);

/*
 * For Test.
 */
int main(void) {

	struct Matrix m1 = MatAlloc(2,2);

	Mx(m1,0,0) = 1;
	Mx(m1,0,1) = 2;
	Mx(m1,1,0) = 3;
	Mx(m1,1,1) = 5;

	MatPrint(m1, "z");

	struct Matrix m2 = MatAlloc(3,3);
	Mx(m2,0,0) = 1;
	Mx(m2,0,1) = 1;
	Mx(m2,1,0) = 1;
	Mx(m2,1,1) = 1;
	MatPrint(m2,"z");

	MatAdd(m1, m2);
	MatPrint(m1,"s");

	MatFree(m1);
	MatFree(m2);

	return EXIT_SUCCESS;
}


/*
 * Print method that takes the Matrix as parameter and print the Matrix.
 */
void MatPrint(struct Matrix M, char messg[]){
	int r,c;
	printf("%s\n", messg);

	for(r=0; r<M.rows; r++){
		for(c=0; c<M.cols; c++){
			printf("%7.3lf", Mx(M,r,c));
		}
		printf("\n");
	}
}


/*
 * Method that takes the rows and columns of Matrix and malloc the memory for the Matrix and return it in the end.
 */
struct Matrix MatAlloc(int rows, int columns){

	struct Matrix *m = malloc(sizeof(struct Matrix));

	m->rows = rows;
	m->cols = columns;

	double **a;
	a = malloc(rows * sizeof (double *));
	for(int i = 0; i<columns; i++){
		a[i] = malloc(columns * sizeof(double));
	}

	m->pX = a;


	return *m;
}

/*
 * Free the memory of malloc Matrix.
 */
void MatFree(struct Matrix M){

	for(int i = 0; i<M.rows; i++){
		free(M.pX[i]);
	}
	free(M.pX);
	free(&M);
}


/*
 * Takes two Matrix as parameters and adds Matrix B to Matrix A.
 */
void MatAdd(struct Matrix A, struct Matrix B){
	if(A.rows == B.rows && A.cols == B.cols){
		for (int i=0; i<A.rows; i++){
			for(int j=0; j<A.cols; j++){
				A.pX[i][j] = A.pX[i][j] + B.pX[i][j];
			}
		}
	}
	else{
		puts("The dimensions of two matrix are different! ");
	}
}



