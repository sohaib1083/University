#include<iostream>
using namespace std;
 
void swap (int &a, int &b)
{
    int temp = a;
    a =b;
    b=temp;
}
void selectionSort(int arr[5][3], int size)
{
    int k, temp, smallest;

    for (int i=0; i<size-1; i++)
    {
        k=i;
        
        for (int j=i+1; j<size; j++)
        {
            if (arr[j][2] < arr[k][2])
            {
                k=j;
            }
        }
        
        swap(arr[i][2], arr[k][2]);
        swap(arr[i][1], arr[k][1]);
        swap(arr[i][0], arr[k][0]);
        
    }
}
void printArray(int arr[5][3], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<arr[i][j]<< "/";
        }
        cout<< endl;
    }
}
int main(void)
{
    int arr[5][3];
    for (int i=0; i<5; i++)
    {
        cout<< "Enter date #"<<i+1<<" : ";
            cout<<"Enter day : ";
            cin>>arr[i][0];
            cout<<"Enter month : ";
            cin>>arr[i][1];
            cout<<"Enter year : ";
            cin>>arr[i][2];
        cout<< endl;    
    }
    selectionSort(arr, 5);
    cout << "Sorted array: \n";
    printArray(arr, 5);
    return 0;
}