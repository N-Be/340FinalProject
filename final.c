#include <stdio.h>
#include <stdlib.h>
#include <time.h>





int randomNumber(int max, int min){
	int randNum = (rand() % (max - min + 1)) + min;
	return randNum;
}


double blockSize(int array[], long size){

	struct timespec start, end;
	long temp = 0;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	printf("Start: %ld\n",start.tv_sec + (1000000 * start.tv_nsec));
	
	for(long i = 0; i < size; i++){
		temp += array[i]; 
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("End: %ld\n",start.tv_sec + (1000000 * end.tv_nsec));
	
	printf("Difference: %f\n\n", ((double)end.tv_nsec) - ((double)start.tv_nsec));
	
	return ((double)end.tv_nsec) - ((double)start.tv_nsec);

}

double timeAtIndex(int array[], long index){

	struct timespec start, end;
	long temp = 0;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	//printf("Start: %ld\n",start.tv_nsec);
	
	temp += array[index];
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	//printf("End: %ld\n",end.tv_nsec);
	
	return ((double)end.tv_nsec) - ((double)start.tv_nsec);
}



int main(int argc, char** argv){
	srand(time(NULL));
	
	int size = 8388608;
	int* array = (int*) malloc(sizeof(int) * size);
	
	char temp;
	
	for(long i = 0; i < size; i++){
		array[i] = randomNumber(0,50);
	}
	
	long double total = 0;
	for(long i = 0; i < 10; i++){
		total += blockSize(array,size);
		//printf("%.2f\n",blockSize(array,size));
	}
	printf("%Lf\n",total/50);
	
	
	for(long i = 1; i <= size; i = i * 2){
		//printf("i = %ld ...  %.2f ns\n",i, timeAtIndex(array,i));
		//timeAtIndex(array,i);
	}


}
