#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> // for sleep()

int i_remaining = 10;
sem_t mutex;

void *eat_icecream(void *arg) {
    int *wallet = (int*) arg;
    while (1) {
        sleep((rand() % 2) + 1);

        sem_wait(&mutex); 
        if (i_remaining <= 0) {
            sem_post(&mutex); 
            break;
        }
        else {
            i_remaining--;
            printf("Thread %ld purchased an ice cream for $1 with $%d from their wallet. %d ice creams remaining.\n", pthread_self(), *wallet, i_remaining);
        }
        sem_post(&mutex); 
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&mutex, 0, 1);

    srand(time(NULL)); 
    int wallets[3] = {10, 5, 2}; 

    pthread_t threads[3];
    int i;
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, eat_icecream, &wallets[i]);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    return 0;
}

