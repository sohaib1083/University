#include <iostream>
using namespace std;

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b= temp;
}

void print (int arr[], int size);

int partition(int *arr, int start , int end)
{
    int mid = (start + end) / 2;
    int pivot = arr[mid];
    int pivot_pos = mid;

    while (start< end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end]> pivot)
        {
            end--;
        }

        if (start< end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap (arr[pivot_pos], arr[end]);
    return end;

}

void quickSort (int *arr, int lb, int ub)
{
    int return_val;
    // divide () & conquer ()
    if (lb < ub)
    {
        return_val = partition (arr, lb, ub);
        quickSort(arr, return_val+1, ub);
        quickSort(arr, lb, return_val-1);
    }
}

void print (int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}
int main (void)
{
    int arr[] = {1, 8, 2, 4, 7, 6, 9, 3, 23, 78, 99, 32};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int size=12;
    int lb = 0;
    int ub = size-1;
    quickSort(arr, lb, ub);
    print(arr, size);
    return 0;
}