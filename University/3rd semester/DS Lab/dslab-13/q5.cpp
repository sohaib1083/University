#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

int minDistance(vector<int> distance, vector<bool> visited, int vertices) {
    int min = INT_MAX, minVertex;
    
    for (int v = 0; v < vertices; v++) {
        if (visited[v] == false && distance[v] <= min) {
            min = distance[v];
            minVertex = v;
        }
    }
    return minVertex;
}

vector<int> dijkstraHelper(vector<vector<int>> &matrix, int vertices, int source) {
    vector<int> distance(vertices, INT_MAX);
    vector<bool> visited(vertices, false);

    // Distance of source to itself is 0.
    distance[source] = 0;

    for(int i = 0; i < vertices; i++){

        int u = minDistance(distance, visited, vertices);

        // visited
        visited[u] = true;
        
        // Update the distances
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && matrix[u][v] && distance[u] != INT_MAX && distance[u] + matrix[u][v] < distance[v]) {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
    }
    return distance;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector< vector<int>> matrix(vertices, vector<int>(vertices,0));

    for (int i = 0; i < vec.size(); i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        if(matrix[u][v]!=0){
            matrix[u][v]=min(matrix[u][v],w);
            matrix[v][u]=min(matrix[v][u],w);
        }
        else{
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
    }
    return dijkstraHelper(matrix, vertices, source);
}
int main (void)
{
    return 0;
}