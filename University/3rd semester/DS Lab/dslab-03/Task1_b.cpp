#include <iostream>
using namespace std;

void fib (int num1, int num2)
{
    if (num1==144)
       return;
    cout<< num1<< " "<< num2<< " ";
    int next = num1+num2;
    fib(next, num2+next);
}

int main (void)
{
    fib(0, 1);
    return 0;
}