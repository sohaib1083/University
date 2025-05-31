#include <iostream>
using namespace std;
void sortArray(int *arr, int n)
{
    int temp, j;
    for (int i=1; i<n; i++)
    {
        temp = arr[i];
        for (j=i-1; j>-1; j--)
        {
            if (arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
void PrintArray(int *arr,int n)
{
    for (int i=0; i<n; i++)
    {
        cout<< arr[i]<<" ";
    }
}
int main (void)
{
    int arr[] = {7, 8, 3, 5, 2};
    int size = 5;
    sortArray(arr, size);
    PrintArray(arr, size);
    return 0;
}