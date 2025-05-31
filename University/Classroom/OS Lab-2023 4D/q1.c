#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 10

int *buffer;
int buffer_index = 0;
int shmid;

sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100;  // Generate a random integer
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[buffer_index++] = item;
        printf("Producer produced item: %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[--buffer_index];
        printf("Consumer consumed item: %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    shmid = shmget((key_t)1234, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    buffer = (int*)shmat(shmid, NULL, 0);
    if (buffer == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);


    return 0;
}

