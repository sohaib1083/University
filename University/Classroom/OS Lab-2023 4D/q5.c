#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#pragma omp parallel for private(i)
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];
    int k = 5;

    for (int i = 0; i < 100; i++) {
        arr[i] = rand()%5;
    }


        bubbleSort(arr, 100);
  
    

    int kthLargest = arr[100-1-k];

    printf("The %dth largest element is: %d\n", k, kthLargest);

    return 0;
}

