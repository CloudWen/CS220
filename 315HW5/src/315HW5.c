/*
 ============================================================================
 Name        : 315HW5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

long Sum(long a, long b);

int main(void) {

	long a, b, c;

	printf("Enter two ints\n");
	scanf("%ld%ld", &a, &b);

	c = Sum(a,b);

	printf("The sum is %ld\n", c);

	return 0;
}
