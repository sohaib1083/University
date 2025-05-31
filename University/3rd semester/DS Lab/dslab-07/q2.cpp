#include <iostream>
using namespace std;

int FindMax(int arr[], int size)
{
    int max = arr[0];
    for (int i=1; i<size; i++)
    {
        if (arr[i]> max)
        {
            max = arr[i];
        }
    }

    return max;
}

void print (int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

void countSort(int arr[], int size, int pos)
{
    int count[10] = { 0 };
    int output[10]= { 0 };

    for (int i=0; i<size; i++)
    {
        count[(arr[i]/pos) % 10]++;
    }

    // cumulative
    for (int i=1; i<10; i++)
    {
        count[i]=count[i]+count[i-1];
    }

    for (int i = size- 1; i >= 0; i--) {
        output[--count[(arr[i] / pos) % 10]] = arr[i];
    }
 
    for (int i = 0; i < size; i++)
        arr[i] = output[i];

}

void RadixSort(int arr[], int size)
{
    int max = FindMax(arr, size);
    for (int pos=1; max/pos>0; pos*=10)
    {
        countSort(arr, size, pos);
    }
}

int main (void)
{
    int arr[] = {35,50,15,25,80,20,90,45};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int size=8;
    int lb = 0;
    int ub = size-1;
    RadixSort(arr, size);
    print(arr, size);
    return 0;
    
}