#include <iostream>
using namespace std;

int binarySearch (int arr[], int l, int r, int key)
{
    int mid;
    int count=0;
    while (l<=r)
    {
    mid = l + (r - l) / 2;    
    count++;
    if (arr[mid]==key)
    {
        cout<< endl<<"no. of iterations in binary search: "<< count<< endl;
        return mid;
    }
    else if (key > arr[mid])
    {
        l=mid+1;
    }
    else if (key< arr[mid])
    {
        r=mid-1;
    }
    }

    return -1;
}

int InterpolationSearch (int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid;
    int count=0;

    while (start<=end)
    {
        mid = start + ((key-arr[start])*(end-start)/(arr[end]-arr[start]));
        // cout<< mid;
        count++;
    
    if (arr[mid]==key)
    {
        cout<<"no. of iterations in interpolation search: "<< count;
        return mid;
    }
    else if (key > arr[mid])
    {
        start=mid+1;
    }
    else if (key< arr[mid])
    {
        end=mid-1;
    }
    }

    return -1;
}


int main (void)
{
    int arr[]={1, 3, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int key = 34;
    int l =0;
    int r = size-1;
    int loc = binarySearch(arr, l, r, key);
    cout<<"Binary search result: "<<loc<< endl<<endl;

    key = 34;
    loc = InterpolationSearch(arr, size, key);
    cout<<endl<<"Interpolation search result: "<<loc<< endl;
    return 0;
}