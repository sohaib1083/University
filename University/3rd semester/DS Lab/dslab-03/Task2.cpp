#include <iostream>
using namespace std;

void fib2 (int num1, int num2);

void fib1 (int num1, int num2)
{
    if (num1==144)
       return;
    cout<< num1<< " "<< num2<< " ";
    int next = num1+num2;
    fib2(next, num2+next);
}

void fib2 (int num1, int num2)
{
    if (num1==144)
       return;
    cout<< num1<< " "<< num2<< " ";
    int next = num1+num2;
    fib2(next, num2+next);
}

int main (void)
{
    fib1(0, 1);
    return 0;
}