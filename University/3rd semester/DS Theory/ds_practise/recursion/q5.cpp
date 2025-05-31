#include <iostream>
#include <vector>
using namespace std;

int CountOnes(unsigned int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num & 1) + CountOnes(num >> 1);
    }
}

int main(void)
{
    cout<<CountOnes(28); // returns 3
}