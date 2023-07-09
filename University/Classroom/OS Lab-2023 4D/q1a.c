#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int i_remaining = 10;
sem_t mutex;

void *eat_icecream() {
    while (1) {
        sem_wait(&mutex); 
        if (i_remaining <= 0) {
            sem_post(&mutex); 
            break;
        }
	else
	{
		i_remaining--;
		printf("Thread %ld ate an ice cream. %d ice creams remaining.\n", pthread_self(), i_remaining);
        }
        sem_post(&mutex); 
     }
}

int main() {
    sem_init(&mutex, 0, 1);

    pthread_t threads[3];
    int i;
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, eat_icecream, NULL);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }


    return 0;
}

