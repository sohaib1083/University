#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

int findMinKey(vector<int> &minEdgeCut, vector<bool> &includedMST, int n)
{
    int min = INT_MAX, min_index=-1;

    for (int v = 0; v < n; v++)
    {
        if (includedMST[v] == false && minEdgeCut[v] < min)
        {
            min = minEdgeCut[v];
            min_index = v;
        }
    }
    return min_index;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < g.size(); i++)
    {
        graph[g[i].first.first - 1][g[i].first.second - 1] = g[i].second;
        graph[g[i].first.second - 1][g[i].first.first - 1] = g[i].second;
    }
    vector<int> parent(n);
    vector<int> minEdgeCut(n);
    vector<bool> includedMST(n);

    for (int i = 0; i < n; i++)
    {
        minEdgeCut[i] = INT_MAX;
        includedMST[i] = false;
    }

    minEdgeCut[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = findMinKey(minEdgeCut, includedMST, n);

        includedMST[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v]!=0 && includedMST[v] == false && graph[u][v] < minEdgeCut[v])
            {
                parent[v] = u;
                minEdgeCut[v] = graph[u][v];
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 1; i < n; i++)
    {
        result.push_back({{parent[i]+1, i+1}, minEdgeCut[i]});
    }

    return result;
}

int main (void)
{
    return 0;
}
