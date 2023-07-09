#include<iostream>
using namespace std;

int main (void)
{
    int arr[10];
    int num, swap;

    // populating
    for (int i=0; i<10; i++)
    {
        cin>> arr[i];
    }

cout<<"printing descending order: "<< endl;
int count=0, mem=999999, greatest;
while(count != 10)
{
    
    greatest = -999999;
    for (int i=0; i<10; i++)
    {
        if (arr[i]>greatest && arr[i]<mem)
        {
            greatest=arr[i];
        }
    }
    cout<<greatest<<" ";
    count++;
    mem=greatest;

}

count=0, mem=-999999;
int least;

cout<<"\nprinting ascending order: "<< endl;
while(count != 10)
{
    least = 999999;
    for (int i=0; i<10; i++)
    {
        if (arr[i]<least && arr[i]>mem)
        {
            least=arr[i];
        }
    }
    cout<<least<<" ";
    count++;
    mem=least;
}
    return 0;
}