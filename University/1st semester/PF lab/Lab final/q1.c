#include<stdio.h>
#include<stdlib.h>

void get_marks(int *ptr, int N)
{
	int i;
	
	printf("Enter marks:");
	for (i=0; i<N; i++)
	{
		scanf("%d", ptr+i);
	}
	
	
}

void display(int *ptr, int N)
{
	int i;
	
	printf("Displaying marks:");
	for (i=0; i<N; i++)
	{
		printf("%d ", *(ptr+i));
	}
	printf("\n");
	
}

float Avg_score(int *ptr, int N)
{
	int i;
	float sum, avg;
	
	for (i=0; i<N; i++)
	{
		sum = sum + *(ptr+i);
	}
	
	avg = sum / i;
	
	return avg;
	
}

void sort(int *ptr, int N)
{
	int i, j, temp;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (*(ptr+j) < *(ptr+i)){
				temp = *(ptr+i);
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
	
	
}

int main (void)
{
	int N;
	int *ptr;
	float avg;
	
	printf("Enter N:");
	scanf("%d", &N);
	
	ptr = (int *)malloc(N * sizeof(int));
	
	
	get_marks(ptr, N);
	display(ptr, N);
	avg = Avg_score(ptr, N);
	
	printf("Average = %f", avg);
	
	printf("\n");
	
	sort(ptr, N);
	
	display(ptr, N); //printing sorted array
}
