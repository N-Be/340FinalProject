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
		total += array[1];	
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	return (((double)end.tv_nsec) - ((double)start.tv_nsec)) / size;
}



int main(int argc, char** argv){
	srand(time(NULL));
	
	//creating array of a size specified here
	int size = 10000000;
	int* array = (int*) malloc(sizeof(int) * size);
	
	
	//populates array with random integers
	for(long i = 0; i < size; i++){
		array[i] = randomNumber(0,50);
	}
	
	printf("%f\n", avgCacheTime(array,size));
	

}
