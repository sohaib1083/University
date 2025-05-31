#include<iostream>
using namespace std;

int main (void)
{
    
    bool arr[5][5] = {{false,true,false,true,true},
    {true,false,true,false,true},
    {false,true,false,false,false},
    {true,false,false,false,true},
    {true,true,false,true,false}};


    int f1,f2,flag = 1;
    
    cout<<"friend number between 0-4: ";
    cin>>f1;
    
    cout<<"friend number between 0-4: ";
    cin>>f2;
    
    cout<<"The common friends of "<<f1<<" and "<<f2<< " : ";
    
    for(int i=0;i<5;i++)
	{
    	if(arr[f1][i] && arr[f2][i])
		{
    		flag = 0;
    		cout<<i<<" ";
		}
	}

	if(flag == 1)
	{
		cout<<"No friends";
	}
    return 0;
}