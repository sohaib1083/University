#include <iostream>
using namespace std;

void printArray(int *arr, int s);

void index(int *arr, int size)
{
    int i=0, j=size-1;
    while (arr[i]< arr[i+1] && i<=size)
    {
        i++;
    }
    while (arr[j]> arr[j+1] && j>=0)
    {
        j--;
    }
    j--;
    cout<< "\nThe sub array has index from "<< i << " to "<< j<< endl;
    // selection  sort
    int min_index;
    for (int a=i-1; a<size; a++)
    {
        min_index=a;
        for (int b=a+1; b<size; b++)
        {
            if (arr[b]< arr[min_index])
            min_index=b;
        }
        swap(arr[min_index], arr[a]);
    }
    cout<<"Sorted Array: "<< endl;
    printArray(arr, size);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b=temp;
}

void printArray(int *arr, int s)
{
    for (int i=0; i<s; i++)
    {
        cout<< arr[i]<< " ";
    }
}

int main (void)
{
    int arr1[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int size1 = 11;
    int arr2[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int size2 = 9;
    cout<< "unsorted array: "<< endl;
    printArray(arr1, size1);
    index(arr1, size1);   
    
    
    cout<< "\n\nunsorted array: "<< endl;
    printArray(arr2, size2);
    index(arr2, size2);  
    return 0;
}