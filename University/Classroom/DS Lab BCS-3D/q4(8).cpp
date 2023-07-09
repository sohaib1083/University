#include <iostream>
using namespace std;
int* sum_of_facts (int num);

int main(void)
{
    int num, count=0, sum=0;
    do{
        cout<<"\nEnter number:";
        cin>> num;

        int *ptr = sum_of_facts(num);
        count=ptr[0];

        if (count>0)
        {
        // printing all factors
        for (int i=1; i<count; i++)
        {
            cout<< ptr[i]<<"  ";
        }
        cout<< "\nThe sum of all factors is: "<<ptr[count];
        }
    } while(num != -1);
    
    return 0;
}

int* sum_of_facts (int num)
{
    int * ptr = new int[num];   
    int sum=0, count=1;
    for (int i=1; i<=num; i++)
    {
        if (num % i == 0)
        {
            sum+=i;
            ptr[count]=i;
            count++;
        }
    }
    ptr[0]=count;// 0th location for count
    ptr[count]=sum;//n+1 location for total sum of factors

    return ptr;
}