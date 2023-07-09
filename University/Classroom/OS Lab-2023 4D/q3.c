#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int matrix[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
    {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
    {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
    {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
    {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
};

int row_sums[10];
int max_sum = 0;
int max_sum_row = 0;

void *calculate_row_sum(void *arg) {
    int row = *((int *)arg);
    int sum = 0;

    for (int j = 0; j < 10; j++) {
        sum += matrix[row][j];
    }

    row_sums[row] = sum;

    if (sum > max_sum) {
        max_sum = sum;
        max_sum_row = row;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int thread_args[10];

    for (int i = 0; i < 10; i++) {
        //thread_args[i] = i;
        pthread_create(&threads[i], NULL, calculate_row_sum, (void *)&i);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Row with the maximum sum: %d\n", max_sum_row);

    return 0;
}

