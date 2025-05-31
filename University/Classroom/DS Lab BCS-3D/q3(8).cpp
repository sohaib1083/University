#include<iostream>
#include<cstring>
using namespace std;

int main (void)
{
    int N;
    int swap;
    cout<<"Enter number of elements: ";
    cin>> N;

    int *ptr = new int[N*2];
    for (int i=0; i<N; i++)
    {
        cin>>*(ptr+i);
    }

    int *desc = new int[N];
    // copying data for descending order array
    for (int i=0; i<N; i++)
    {
        *(desc+i)=*(ptr+i);
    }

    // sorting in descending order
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (*(desc+i)<*(desc+j))
            {     
                swap =*(desc+i);
                *(desc+i)=*(desc+j);
                *(desc+j)=swap;
            }
        }
    }
    
    int *asc = new int[N];
    // copying data for ascending order array
    for (int i=0; i<N; i++)
    {
        *(asc+i)=*(ptr+i);
    }


    // sorting in ascending order
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (*(asc+i)>*(asc+j))
            {   
                swap =*(desc+i);
                *(desc+i)=*(desc+j);
                *(desc+j)=swap;
            }
        }
    }

    for (int i=0, j=0; i<N*2, j<N; i+=2, j++)
    {
        *(ptr+i)=*(desc+j);
    }
    
    for (int i=1, j=0; i<N*2, j<N; i+=2, j++)
    {
        *(ptr+i)=*(asc+j);
    }

    for(int i=0; i<N*2; i++)
    {
        cout<<*(ptr+i)<<" ";
    }

    return 0;
}