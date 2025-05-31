#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define threads 4

char str[100];

void *reverse(void *arg)
{
	int *start = (int *)arg, i;
	int size = strlen(str)/threads;
	
	char temp[size];
	
	for(i=*start; i<*start+size; i++)
	{
		temp[i] = str[i];
	} 
	int j=*start;
	for(i=*start+size-1; i>=*start; i--)
	{
		str[j] = temp[i];
		j++;
	}
	return NULL;
}


int main()
{
	
	printf("Enter a string: ");	
	scanf("%s", str);
	
	pthread_t th[threads];
	int i;
	
	int s = strlen(str);
	s /= threads;
	
	for(i=0; i<threads; i++)
	{
		int *j = (int *)malloc(sizeof(int));
		*j = i*s;
		pthread_create(&th[i], NULL, &reverse, (void *)j);		
	}
	
	for(i=0; i<threads; i++)
	{
		pthread_join(th[i], NULL);
	}	
			
	printf("\n%s\n", str);

	return 0;
}
