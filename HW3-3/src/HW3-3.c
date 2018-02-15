/*
 ============================================================================
 Name        : HW3-3.c
 Author      : Pengtao Wen
 Version     :
 Copyright   : Your copyright notice
 Description : Reading in formatted data and generating a report.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	/**
	 * open the file.
	 */
	printf("%-30s %30s\n", "STATE","TOTAL");
	printf("%s\n","---------------------------------------------------------------");
	FILE *file = fopen("stateoutflow0708.txt", "r");

	char tmp[255];
	fgets(tmp, 255, (FILE*)file);
	char copy[255];
	strcpy(copy, tmp);
	fgets(tmp, 255, (FILE*)file);
	int result = strcmp(copy, tmp);
	int total = 0;

	/**
	 * while loop keep reading different lines of the file.
	 */
	while(result != 0){
		char copy2[255];
		strcpy(copy2, tmp);
		char *test = strtok(tmp, "\t");
		char test2[255];
		strcpy(test2, test);
		char *test22 = strtok (test2, "\"");
		char *copy3 = strtok(copy2, "\t");
		int count = 0;

		/**
		 * Condition of the target.
		 */
		if(strcmp(test22,"25") == 0){
			while(copy3 != NULL){
				copy3 = strtok(NULL, "\t");
				count++;
				if(count == 5){
					printf("%-30s ", copy3);
				}
				else if(count == 8){
					printf("%30s ", copy3);
					int a = atoi(copy3);
					total += a;
				}
			}
		}
		strcpy(copy, tmp);
		fgets(tmp, 255, (FILE*)file);
		result = strcmp(copy, tmp);
	}

	puts("-------------------------------------------------------------");
	printf("%-30s%30d","TOTAL", total);

	fclose(file);

	return EXIT_SUCCESS;
}
