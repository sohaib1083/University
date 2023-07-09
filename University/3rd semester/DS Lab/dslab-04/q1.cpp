#include <iostream>
using namespace std;

void swap (string &a, string&b)
{
    string s = b;
    b = a;
    a=s;
}

int main (void)
{
    
    string arr[]={"Red", "Green", "Blue", "Yellow", "Pink"};
    int size=5, flag;
    for (int i=0; i<size; i++)
    {
        flag=0;
        for (int j=0; j< size-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag=1;
            }
        }
        if (flag == 0)
           break;
    }

    for (int i =0; i<size; i++)
    {
        cout<< arr[i]<< " ";
    }
    return 0;
}