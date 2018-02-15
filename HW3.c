/*
 ============================================================================
 Name        : HW3.c
 Author      : Pengtao Wen
 Version     :
 Copyright   : Your copyright notice
 Description : Circular right shift on array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int * circular_right_shift( int array[], int size, int shift );

int main(void) {

	int input_array[20];
	int input_size;
	int input_shift;
	puts("Please input the size of the array(Less/Equal to 20): ");
	scanf("%d", &input_size);
	puts("Please enter the integers for the array(Every time after typing the number, press Enter): ");
	for(int i=0; i<input_size; i++){
		scanf("%d", &input_array[i]);
	}
	puts("Please enter the amount of right shift: ");
	scanf("%d", &input_shift);
	while(input_shift > input_size || input_shift < 0){
		printf("Invalid integer input, the range should be 0-%d, please input again: ", input_size);
		scanf("%d", &input_shift);
	}

	int *result;
	result = circular_right_shift(input_array, input_size, input_shift);
	puts("After the right shift: ");
	for (int i = 0; i<input_size; i++){
		printf("%d, ", *(result+i));
	}
	return EXIT_SUCCESS;
}

/**
 * Function that takes the array, the size of the array, and the amount of the right shift.
 * After finish the right shift, return the result array.
 */
int * circular_right_shift( int array[], int size, int shift ){

	static int temp[20];
	int array_index = size - shift;
	int endpoint = size - shift;
	for (int temp_index = 0; temp_index <= size -1; temp_index++){
		if(array_index < endpoint){
					temp[temp_index] = array[array_index];
					array_index++;
		}
		else if(array_index <= size-1){
			temp[temp_index] = array[array_index];
			array_index++;
		}
		else if(array_index > size-1){
			array_index = 0;
			temp_index--;
		}

	}
	return temp;
}
