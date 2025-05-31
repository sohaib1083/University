#include <iostream>
#include <vector>
using namespace std;

vector<int> concat(const vector<vector<int>> &lists, int start, int end)
{
    vector<int> result;
    if (start == end)
    {
        return result;
    }
    else
    {
        vector<int> current = lists[start];
        result.insert(result.end(), current.begin(), current.end());
        vector<int> rest = concat(lists, start + 1, end);
        result.insert(result.end(), rest.begin(), rest.end());
        return result;
    }
}

int main(void)
{
    vector<vector<int>> lists = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = concat(lists, 0, lists.size());
}