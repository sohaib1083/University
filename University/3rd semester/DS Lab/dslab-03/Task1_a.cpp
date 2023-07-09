#include <iostream>
using namespace std;

void seq1 (int n, int count)
{
	
    if (n==28)
        exit(0);
        
    cout<< n<< " ";
	    
    seq1(n+count, ++count);

}

int main (void)
{
    int n;
    //cin>> n;
    n=1;
    int count=1;
    seq1(n, count);


    return 0;
}