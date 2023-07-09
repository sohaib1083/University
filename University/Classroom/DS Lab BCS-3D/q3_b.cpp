#include<iostream>
using namespace std;

void insert (int arr[], int &size, int val)
{
    size++;
    int index = size;
    arr[index]=val;

    while (index > 1)
    {
        int parent = index/2;
        if (arr[index]<arr[parent]){
            swap(arr[index], arr[parent]);
            index=parent;
        }
        else{
            return;
        }
    }
}

void delete_val (int arr[], int &size, int val)
{
    //search
    int i;
    for (i=1; i<=size; i++){
        if (arr[i]==val){
            break;
        }
    }

    if (i<=size){
        arr[i]= arr[size];
        size--;
    }
    else if (arr[i]== val){
        arr[i]=0;
        size--;
    }
    else{
        cout<<"Value not found";
    }

    while (i< size){
        int left_child = i/2;
        int right_child = i/2 + 1;

        if (arr[left_child]< arr[i] && left_child< size){
            swap (arr[left_child], arr[i]);
        }
        else if (arr[right_child]< arr[i] && right_child< size){
            swap(arr[left_child], arr[i]);
        }
        else {
            return;
        }
    }
}

void print (int arr[], int size)
{
    for (int i=1; i<=size; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<< endl;
}

int main (void)
{
    int arr_input[] ={35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int size_input = 10;

    int arr[100];
    int size=0;    
    
    for (int i=0; i<size_input; i++){
        insert(arr, size, arr_input[i]);
    }

    print(arr, size);
    delete_val(arr, size, 35);
    print(arr, size);
    return 0;
}
