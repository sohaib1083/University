#include <iostream>
#include <vector>
using namespace std;

int min(const vector<int> &numbers, int start, int end, int minSoFar)
{
    if (start == end)
    {
        return minSoFar;
    }
    else
    {
        int current = numbers[start];
        if (current < minSoFar)
        {
            minSoFar = current;
        }
        return min(numbers, start + 1, end, minSoFar);
    }
}

int main(void)
{
    vector<int> numbers = {7, 3, 5, 9, 1};
    cout<< min(numbers, 0, numbers.size(), numbers[0]);
}