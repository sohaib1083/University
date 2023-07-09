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

    // starts from index 0
    int arr_input[] ={35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int size = 10;
    
    for (int i=size/2 -1; i>=0; i--){
        heapify(arr_input, size, i);
    }

    print(arr_input, size);

    HeapSort(arr_input, size);
    cout<< "After sorting: "<< endl;
    print(arr_input, size);
    return 0;
}