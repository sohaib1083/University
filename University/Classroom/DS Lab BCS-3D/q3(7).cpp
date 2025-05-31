#include <iostream>
using namespace std;

int main(void)
{
    int num;
    do{
    cout<<"\nEnter number:";
    cin>> num;
    int sum=0;

    for (int i=1; i<=num; i++)
    {
        if (num % i == 0)
        {
            sum+=i;
            cout<< i<< "  ";
        }
    }
    if (num != -1)
    {
        cout<< "\nThe sum of all factors is: "<<sum;
    }
    } while(num != -1);
    
    return 0;
}
