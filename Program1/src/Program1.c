/*
 ============================================================================
 Name        : Program1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double area_circle( int radius );
int area_rectangle( int length, int width );
int area_square( int side );
double area_triangle ( int base, int height );

int main(void) {
	int option =-1;
	while(option != 0){
		puts("Please select a graph to calculate the area(1:circle, 2:rectangle, 3:square, 4:triangle, 0:to exit):"); /* prints the menu for options */
		scanf("%d", &option);	/* takes the option input */
		if (option == 1){
			int radius;
			printf("Please in;put the radius: \n");
			scanf("%d", &radius);
			printf("The area of this circle is: %f\n", area_circle(radius));
		}
		else if(option == 2){
			int length;
			int width;
			printf("Please input the length and width: \n");
			scanf("%d", &length);
			scanf("%d", &width);
			printf("The area of this rectangle is: %d \n", area_rectangle(length, width));
		}
		else if(option == 3){
			int side;
			printf("please input the side: \n");
			scanf("%d", &side);
			printf("The area of this square is: %d \n", area_square(side));
		}
		else if(option == 4){
			int base;
			int height;
			printf("Please input the base and height: \n");
			scanf("%d", &base);
			scanf("%d", &height);
			printf ("The area of this triangle is: %f \n", area_triangle(base, height));
		}
		else if (option == 0){	/* jump out the while loop when input is 0 */
			break;
		}
	}
	return EXIT_SUCCESS;
}

/**
 * Return the area of a circle with given radius.
 */
double area_circle( int radius ){
	return radius * radius * 3.14159;
//	return area;
}

/**
 * Return the area of a rectangle with given length and width.
 */
int area_rectangle( int length, int width ){
	int area = length * width;
	return area;
}

/**
 * Return the area of a square with given side.
 */
int area_square ( int side ){
	int area = side * side;
	return area;
}

/**
 * Return the area of a triangle with given base and height.
 */
double area_triangle ( int base, int height ){
	double area = base * height * 0.5;
	return area;
}
