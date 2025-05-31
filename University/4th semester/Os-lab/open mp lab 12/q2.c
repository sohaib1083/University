#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#define n 1000

int main (void)
{
	srand(0);
	int arr[n];
	int max = rand() % 99 + 1;
	arr[0]=max;
	int mx_index=0, i;
	#pragma omp parallel for shared(default) private(i)	
	for (i=1; i<n; i++){
		arr[i] = rand() % 100 + 1;
		#pragma omp critical
		if (arr[i] > max){
			max=arr[i];
			mx_index=i;
		}	
			
	}	
	printf("The largest element is %d at the index %d.\n", max, mx_index); 
	return 0;
}
