/*
 ============================================================================
 Name        : prog2.c
 Author      : 
 Version     :
 Copyright   :
 Description : Serial version of calculate histogram program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>


#define NUMBINS 1000
#define atoa(x) #x

int *histogramVals;    /*global histogram array for all threads*/
float binSize;		   /*bin size calculated from min and max of array values*/

int calcHistogram (float* data, int numDataPoints, int numBins);

int main(void) {

	clock_t start = clock();

	float rawData[1000000];

	histogramVals =  malloc(NUMBINS * sizeof(int));

	FILE *fileIn = fopen("numbers.bin", "rb");
	if (fileIn == NULL){
		printf("File not opened\n");
		return 0;
	}


	int cnt = 1000000;
	int resultCode;

	resultCode = fread(rawData, sizeof(rawData[0]), sizeof(rawData)/sizeof(rawData[0]), fileIn);

	fclose(fileIn);

	calcHistogram (rawData, cnt, NUMBINS);

	FILE *fileOut = fopen("a.txt", "w");
	int resultCode2;

	for (int cnt1 = 0; cnt1 < NUMBINS; cnt1++){
		printf("bin: %d  binStart: %f   binEnd:  %f  Histogram Value: %d\n", cnt1, binSize*(float)cnt1, binSize*(float)(cnt1+1), histogramVals[cnt1]);
//		char s[10];
//		sprintf(s, "%d ", histogramVals[cnt1]);
//		resultCode2 = fputs(s, fileOut);
	}
	fclose(fileOut);

	clock_t end = clock();
	printf("%f seconds\n", (double)(end-start)/(double)CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}



/*-------------------------------------------------------------------
 * Function:    calcHistogram
 * Purpose:     Calculate Histogram result is in a global variable histogramVals.
 * In args:     data:  values to be histogrammed.
 *              numDataPoints:  Number of data points to be histogrammed.
 *              numBins:  Number of bins in output histogram
 * Outputs:     Histogram of values stored in global histogramVals
				binSize in global variable.
 *
 */

int calcHistogram (float* data, int numDataPoints, int numBins) {
	float maxVal = FLT_MIN;
	float minVal = FLT_MAX;

	for(int cnt = 0; cnt < numDataPoints; cnt++ ) {
		if ( data[cnt] > maxVal ) maxVal = data[cnt];
		if ( data[cnt] < minVal ) minVal = data[cnt];
	}

	binSize = (maxVal-minVal)/(float)numBins;
	printf("minVal: %f  maxVal: %f  binSize: %f\n", minVal, maxVal, binSize);

	for (int i = 0; i < numDataPoints; i++){
		int binNum = (int)((data[i] - minVal) / binSize);
		histogramVals[binNum]++;
	}
	return 0;
}

