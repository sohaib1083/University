#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

// had to add a class to the code given in the pdf
class Graph
{
private:
    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;

    adj = new vector<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<int> queue;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);
    vector<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}
int main()
{
    Graph G(10);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(5, 6);
    G.addEdge(3, 1);
    G.addEdge(3, 3);
    G.addEdge(3, 5);
    G.addEdge(1, 6);
    G.addEdge(2, 4);
    G.addEdge(1, 3);
    G.addEdge(5, 4);
    G.addEdge(5, 7);
    G.addEdge(6, 3);
    G.addEdge(7, 1);
    
    G.BFS(0);
}