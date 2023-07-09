#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define n 1000
int main (void){
	int arr[n];
	int i;
	
	srand(time(0));
	
	for (i=0; i<n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	
	int temp, j;
	#pragma omp parallel for shared(default) private(i,j)
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				#pragma omp critical 
				if(arr[j] < arr[i])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}		
	
	
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\n");
	
	return 0;
}
