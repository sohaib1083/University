#include <iostream>
using namespace std;

double average(const int *numbers, int start, int end, double sum)
{
    if (start == end-1)
    {
        return (sum +numbers[start])/ end;
    }
    else
    {
        return average(numbers, start + 1, end, sum + numbers[start]);
    }
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    cout<< average(numbers, 0, sizeof(numbers) / sizeof(int), 0);
}