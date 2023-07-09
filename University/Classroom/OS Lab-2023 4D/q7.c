#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TRACK_DISTANCE 100 

int runner1_pos = 0;
int runner2_pos = 0;
sem_t semaphore;

void* runner1(void* arg) 
{
    while (runner1_pos < TRACK_DISTANCE && runner2_pos < TRACK_DISTANCE) {
        sem_wait(&semaphore);
        
        int step = rand()%5 + 1;
        runner1_pos += step;
        sem_post(&semaphore); 
    }

    return NULL;
}

void* runner2(void* arg) {
    while (runner1_pos < TRACK_DISTANCE && runner2_pos < TRACK_DISTANCE) {
        sem_wait(&semaphore); 
        int step = rand()%5 + 1;
        runner2_pos += step;
        sem_post(&semaphore); 
    }

    return NULL;
}

int main() 
{

    sem_init(&semaphore, 0, 1);

    pthread_t runner1_thread, runner2_thread;

    pthread_create(&runner1_thread, NULL, runner1, NULL);
    pthread_create(&runner2_thread, NULL, runner2, NULL);

    pthread_join(runner1_thread, NULL);
    pthread_join(runner2_thread, NULL);

    if (runner1_pos >= TRACK_DISTANCE && runner2_pos >= TRACK_DISTANCE) {
        printf("It's a tie!\n");
    } 
    else if (runner1_pos >= TRACK_DISTANCE) {
        printf("Runner 1 wins the race!\n");
    }
    else {
        printf("Runner 2 wins the race!\n");
    }

    return 0;
}

