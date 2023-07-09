#include <iostream>
using namespace std;

bool canWin(const int *nums, int size, int p1, int p2)
{
    if (size == 0)
    {
        return p1 > p2;
    }
    else
    {
        int front = nums[0];
        int back = nums[size - 1];
        return !canWin(nums + 1, size - 1, p2, p1 + front) || !canWin(nums, size - 1, p2, p1 + back);
    }
}

int main(void)
{
    int nums[] = {1, 5, 2};
    cout << canWin(nums, sizeof(nums) / sizeof(int), 0, 0);
}