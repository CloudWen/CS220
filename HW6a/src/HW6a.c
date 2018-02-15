/*
 ============================================================================
 Name        : HW6a.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int * calculate_prefix_sums( int array[], int size);
int sum;

int main(void) {
	sum = 0;

	int input_array[10] = {1,2,3,4,5,6,7,8,9,10};
	int input_size = 10;

	int *prefix_sums = calculate_prefix_sums(input_array, input_size);
	puts("After calculate: ");
	for (int i=0; i<input_size; i++){
		printf("%d,", *(prefix_sums+i));
	}

	return EXIT_SUCCESS;
}


int * calculate_prefix_sums(int array[], int size){

	static int prefix_sums[20];
	for (int i=0; i<size; i++){
		sum+=array[i];
		prefix_sums[i] = sum;
	}
	return prefix_sums;
}



