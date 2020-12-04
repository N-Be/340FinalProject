/*
Nathan Bell
Hollande Powell
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>





int randomNumber(int max, int min){
	int randNum = (rand() % (max - min + 1)) + min;
	return randNum;
}



double avgCacheTime(int array[],int size){
	struct timespec start, end;
	double total = 0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	
	for(int i = 0; i < size; i++){
		total += array[0];
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	return (((double)end.tv_nsec) - ((double)start.tv_nsec))/size;
}


double avgMainMemoryTime(int array[], int size){
	struct timespec start, end;
	double total = 0;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	for(int i = 512; i < size; i= i * 2){
		total += array[i];	
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	
	return (((double)end.tv_nsec) - ((double)start.tv_nsec))/16;
}


int main(int argc, char** argv){
	srand(time(NULL));
	
	//creating array of a size specified here
	int size = 67108864;
	int* array = (int*) malloc(sizeof(int) * size);
	
	
	//populates array with random integers
	for(long i = 0; i < size; i++){
		array[i] = randomNumber(0,50);
	}
	
	//
	printf("mm: %f\n", avgMainMemoryTime(array,size));
	printf("cm: %f\n", avgCacheTime(array,size));
}











/*int method(int array[], int sizes[]){*/

/*	struct timespec start, end;*/
/*	long temp = 0;*/
/*	*/
/*	for(int i = 0; i < 23; i++){*/
/*		int size = sizes[i];*/
/*	*/
/*		clock_gettime(CLOCK_MONOTONIC, &start);*/
/*	*/
/*		for(int j = 0; j < size; j++){*/
/*			temp += array[j]; */
/*		}*/
/*		clock_gettime(CLOCK_MONOTONIC, &end);*/
/*		printf("i = %d %.2f\n",i,((double)end.tv_nsec) - ((double)start.tv_nsec));*/
/*	}*/
/*}*/


/*	double tempTime = 0;*/
/*	double total = 0;*/
/*	for(long i = 0; i < 10; i++){*/
/*	 	tempTime = blockSize(array,size);*/
/*	 	if(temp > 0){*/
/*	 		total += tempTime;*/
/*	 	}*/
/*		//printf("%.2f\n",blockSize(array,size));*/
/*	}*/
/*	printf("%f\n",total/10);*/
	
/*	for(long i = 1; i <= size; i = i * 2){*/
/*		printf("i = %ld ...  %.2f ns\n",i, timeAtIndex(array,i));*/
/*	}*/
/*	*/
/*	int sizes[23];*/
/*	*/
/*	*/
/*	for(int i = 0; i < 23; i++){*/
/*		sizes[i] = temp;*/
/*		temp = temp * 2;*/
/*	}*/
/*	*/
/*	method(array,sizes);*/

/*double blockSize(int array[], long size){*/

/*	struct timespec start, end;*/
/*	long temp = 0;*/
/*	*/
/*	clock_gettime(CLOCK_MONOTONIC, &start);*/
/*	//printf("%ld\n",start.tv_sec + (1000000 * start.tv_nsec));*/
/*	*/
/*	for(long i = 0; i < size; i++){*/
/*		temp += array[i]; */
/*	}*/
/*	*/
/*	clock_gettime(CLOCK_MONOTONIC, &end);*/
/*	//printf("%ld\n",start.tv_sec + (1000000 * end.tv_nsec));*/
/*	*/
/*	//printf("Difference: %f\n\n", ((double)end.tv_nsec) - ((double)start.tv_nsec));*/
/*	*/
/*	return ((double)end.tv_nsec) - ((double)start.tv_nsec);*/

/*}*/

/*double timeAtIndex(int array[], long index){*/

/*	struct timespec start, end;*/
/*	long temp = 0;*/
/*	*/
/*	clock_gettime(CLOCK_MONOTONIC, &start);*/
/*	//printf("Start: %ld\n",start.tv_nsec);*/
/*	*/
/*	temp += array[index-1];*/
/*	*/
/*	clock_gettime(CLOCK_MONOTONIC, &end);*/
/*	//printf("End: %ld\n",end.tv_nsec);*/
/*	*/
/*	return ((double)end.tv_nsec) - ((double)start.tv_nsec);*/
/*}*/
