#include <iostream>
using namespace std;
void selectionSort(int *arr, int size)
{
    int min_index;
    for (int i=0; i<size; i++)
    {
        min_index=i;
        for (int j=i+1; j<size; j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}
void printArray(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        cout<< arr[i]<< " ";
    }
}
int main (void)
{
    int arr[]={1, 8, 2, 3, 7, 4};   
    selectionSort(arr, 6);
    printArray(arr, 6);
    return 0;
}