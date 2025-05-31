#include<iostream>
using namespace std;

int main (void)
{
    int arr[3][3], count=0, count_ones=0;
    int i,j;
    // reading elements
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            cout << "Enter row #" << i+1 << " and column #" << j+1 << " of the matrix: ";
            cin>>arr[i][j];             
        }
    }
  
  
    // checking
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if (i==j && arr[i][j]==1)
            {
                count_ones++;
            }
            else if(arr[i][j] != 0)
            {
                count++;
            }               
        }  
    }

    if (count_ones==3 && count == 0)
    {
        cout<<"Identity matrix";
    }    
    
    
    
    return 0;
}