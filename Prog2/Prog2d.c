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
	int* histogramVals;
	float minVal;
	int start;
	int end;
};

struct thread_struct{
	int* h1;
	int* h2;
	int* h3;
	int* h4;
	int* result;
	long tid;
};

//int *histogramVals;    /*global histogram array for all threads*/
float binSize;		   /*bin size calculated from min and max of array values*/

int calcHistogram (float* data, int numDataPoints, int numBins);
void* thread(void* threadid);
void* counting(void* arg);

int main(void) {

	clock_t start = clock();

	float rawData[1000000];

//	struct arg_struct args[NUM_THREADS];

//	histogramVals =  malloc(NUMBINS * sizeof(int));

	FILE *fileIn = fopen("numbers.bin", "rb");
	if (fileIn == NULL){
		printf("File not opened\n");
		return 0;
	}


	int cnt = 1000000;
	int resultCode;

	resultCode = fread(rawData, sizeof(rawData[0]), sizeof(rawData)/sizeof(rawData[0]), fileIn);

	fclose(fileIn);

//	calcHistogram (rawData, cnt, NUMBINS);



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

		struct thread_struct tss[NUM_THREADS];
		int *histogramVals =  malloc(NUMBINS * sizeof(int));
		for (int t=0; t<NUM_THREADS; t++){
			tss[t].tid = t;
			tss[t].h1 = args[0].histogramVals;
			tss[t].h2 = args[1].histogramVals;
			tss[t].h3 = args[2].histogramVals;
			tss[t].h4 = args[3].histogramVals;
			tss[t].result = histogramVals;

			rc = pthread_create(&threads[t], NULL, counting, &tss[t]);
			if(rc){
				printf("ERROR; return code from pthread_create() is %d \n", rc);
				exit(-1);
			}

//			for(int i=0; i<NUMBINS; i++){
//				histogramVals[i] += args[t].histogramVals[i];
//			}
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
//	float maxVal = FLT_MIN;
//	float minVal = FLT_MAX;
//
//	for(int cnt = 0; cnt < numDataPoints; cnt++ ) {
//		if ( data[cnt] > maxVal ) maxVal = data[cnt];
//		if ( data[cnt] < minVal ) minVal = data[cnt];
//	}
//
//	binSize = (maxVal-minVal)/(float)numBins;
//	printf("minVal: %f  maxVal: %f  binSize: %f\n", minVal, maxVal, binSize);
//
//
//	pthread_t threads[NUM_THREADS];
//	int rc;
//	long t;
//	struct arg_struct args[NUM_THREADS];
//	for(t=0; t<NUM_THREADS; t++){
//
//		args[t].tid = t;
//		args[t].rawData = data;
//		args[t].minVal = minVal;
//
//
//		rc = pthread_create(&threads[t], NULL, thread, &args[t]);
//		if(rc){
//			printf("ERROR; return code from pthread_create() is %d \n", rc);
//			exit(-1);
//		}
//	}



//	for (int i = 0; i < numDataPoints; i++){
//		int binNum = (int)((data[i] - minVal) / binSize);
//		histogramVals[binNum]++;
//	}
	return 0;
}

void* thread(void*	arg){

	struct arg_struct * as = (struct arg_struct *) arg;


	int *histogramVals =  malloc(NUMBINS * sizeof(int));
	long tid;
	tid = (long) as->tid;
	int start = tid * (1000000/NUM_THREADS);
	int end = start + (1000000/NUM_THREADS);
	for( int i = start; i < end; i++){
		int binNum = (int)((as->rawData[i] - as->minVal) / binSize);
		histogramVals[binNum]++;
	}
	as->histogramVals = histogramVals;
	as->start = start;
	as->end = end;
	pthread_exit(NULL);
}

void* counting(void* arg){

	struct thread_struct * ts = (struct thread_struct *) arg;
	long tid;
		tid = (long) ts->tid;
		int start = tid * (NUMBINS/NUM_THREADS);
		int end = start + (NUMBINS/NUM_THREADS);
		for(int i = start; i<end; i++){
			ts->result[i] = ts->h1[i]+ts->h2[i]+ts->h3[i]+ts->h4[i];
		}
		pthread_exit(NULL);

}
