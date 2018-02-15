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
#include <pthread.h>

#define NUMBINS 1000
#define NUM_THREADS 4

struct arg_struct{
	float* rawData;
	long tid;
	float minVal;
};

int *histogramVals;    /*global histogram array for all threads*/
float binSize;		   /*bin size calculated from min and max of array values*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int calcHistogram (float* data, int numDataPoints, int numBins);
void* thread(void* threadid);

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

	float maxVal = FLT_MIN;
		float minVal = FLT_MAX;

		for(int cnt2 = 0; cnt2 < cnt; cnt2++ ) {
			if ( rawData[cnt2] > maxVal ) maxVal = rawData[cnt2];
			if ( rawData[cnt2] < minVal ) minVal = rawData[cnt2];
		}

		binSize = (maxVal-minVal)/(float)NUMBINS;
		printf("minVal: %f  maxVal: %f  binSize: %f\n", minVal, maxVal, binSize);



	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	struct arg_struct args[NUM_THREADS];
	for(t=0; t<NUM_THREADS; t++){

		args[t].tid = t;
		args[t].rawData = rawData;
		args[t].minVal = minVal;


		rc = pthread_create(&threads[t], NULL, thread, &args[t]);
		if(rc){
			printf("ERROR; return code from pthread_create() is %d \n", rc);
			exit(-1);
		}


	}

	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}

	for (int cnt1 = 0; cnt1 < NUMBINS; cnt1++){
		printf("bin: %d  binStart: %f   binEnd:  %f  Histogram Value: %d\n", cnt1, binSize*(float)cnt1, binSize*(float)(cnt1+1), histogramVals[cnt1]);
	}

	clock_t end = clock();
	printf("%f seconds\n", (double)(end-start)/(double)CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}

void* thread(void*	arg){

	struct arg_struct * as = (struct arg_struct *) arg;

	long tid;
	tid = (long) as->tid;
	int start = tid * (1000000/NUM_THREADS);
	int end = start + (1000000/NUM_THREADS);
	for( int i = start; i < end; i++){
		int binNum = (int)((as->rawData[i] - as->minVal) / binSize);
		pthread_mutex_lock(&mutex);
		histogramVals[binNum]++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

