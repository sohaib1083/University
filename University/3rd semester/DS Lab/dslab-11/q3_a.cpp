#include<iostream>
using namespace std;

void insert (int arr[], int &size, int val)
{
    size++;
    int index = size;
    arr[index] = val;
    
    while (index > 1)
    {
        int parent_index = index/2;

        if (arr[parent_index]< arr[index]){
            swap(arr[parent_index], arr[index]);
            index = parent_index;
        }
        else{
            return;
        }
    }
}

void delete_val (int arr[], int &size, int val)
{
    //search element
    int i;
    for (i=1; i<size; i++){
        if (arr[i]==val){
            break;
        }
    }
    if (i<size){
        arr[i]=arr[size];
        size--;
    } // swap with last element
    else if (arr[size]==val){
        arr[size]=0;
        size--;
    }
    else{
        cout<<"value not found";
    }

    while (i < size)
    {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;

        if (left_child <= size && arr[i]<arr[left_child]){
            swap(arr[i], arr[left_child]);
            i=left_child;
        } 
        else if (right_child<=size && arr[i]< arr[right_child]){
            swap(arr[i], arr[right_child]);
            i=right_child;
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
    delete_val(arr, size, 42);
    print(arr, size);
    return 0;
}
