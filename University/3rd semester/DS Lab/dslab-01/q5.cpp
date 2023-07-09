#include<iostream>
using namespace std;

void MinMax(int *ptr_max, int *ptr_min, int *arr, int num)
{
    *ptr_max=arr[0];
    *ptr_min=arr[0];

    for (int i=0; i<num; i++)
    {
        if(arr[i] > *ptr_max)
        {
            *ptr_max=arr[i];
        }
        
        if(arr[i] < *ptr_min)
        {
            *ptr_min=arr[i];
        }
    }
}

int main (void)
{
    int num;
    cout<< "Enter number of elements in array: ";
    cin>> num;

    int *ptr= new int[num];
    int min, max;
    for (int i=0; i<num; i++)
    {
        cin>>*(ptr+i);
    }
    MinMax(&max, &min, ptr, num);

    cout<<"\nThe maximum number is: "<<max;
    cout<<"\nThe minimum number is: "<<min;
    
    return 0;
}