#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    if (n==1)
    {
        return;
    }

    static int count=0;

    for (int i=0; i<n; i++)
    {
        if (arr[i]> arr[i+1])
        {
            swap(arr[i+1], arr[i]);
            count++;
        }
    }

    if (count == 0)
    {
        return;
    }

    sort (arr, n-1);    

}


int main (void)
{
    int arr[] ={12, 11, 13, 5, 6, 7};

    int len = (sizeof(arr))/sizeof(arr[0]);
    int len_copy = len;
    cout<< len<< len_copy << endl;
    sort(arr, len);

    
    cout<<len << len_copy;


    cout<< "\nsorted array:";
    for (int i=0; i<=len; i++)
    {
        cout<< arr[i]<< " ";
    }
    return 0;
}