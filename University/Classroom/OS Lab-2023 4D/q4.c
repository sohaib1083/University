#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


sem_t s;
int arr[10] = {1, 2, 3, 4, 6, 5, 7, 8, 9, 10};

void * odd(void * args){
	sem_wait(&s);
	int sum=0;
	for (int i=0; i<10; i++)
	{
		if (arr[i] % 2 != 0)
		{
			sum += arr[i];
		}	
	}
	printf("The sum of odd number: %d.\n", sum);
	sem_post(&s);
	
		
}

void * even(void * args)
{
	sem_wait(&s);
	int sum=0;
	for (int i=0; i<10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			sum += arr[i];
		}
	}
	printf("The sum of even number: %d.\n", sum);
	sem_post(&s);
		
}


int main (void)
{
	sem_init(&s, 0, 1);
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, odd, NULL);
	pthread_create(&t2, NULL, even, NULL);
	
	pthread_join(t1, NULL);
		pthread_join(t2, NULL);
	return 0;
}
