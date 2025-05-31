#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;

    if (left < n && arr[left]>arr[largest]){
        largest = left;
    }
    if (right < n && arr[right]>arr[largest]){
        largest=right;
    }

    if (largest != i){
        swap (arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int size)
{
    int t = size-1;

    while (t > 0){
        // step 1
        swap(arr[0], arr[t]);
        t--;
        // step 2
        heapify(arr,t , 0);
    }
}

void BuildHeap (int arr[], int N)
{
    for (int i=N/2 -1; i>=0; i--){
        heapify(arr, N, i);
    }
}


void print (int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<< endl;
}

int main (void)
{
    int N = 5;
    int arr_input[] = {4,1,3,9,7};

    BuildHeap(arr_input, N);
    print(arr_input, N);

    HeapSort(arr_input, N);
    cout<< "After sorting: "<< endl;
    print(arr_input, N);
    return 0;
}