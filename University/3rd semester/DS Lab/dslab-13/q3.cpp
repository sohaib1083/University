#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    void insert(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        temp->next = newNode;
        newNode->prev = temp;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data + 1 << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Graph
{
private:
    DoublyLinkedList *graphNodes;
    int nodeCount;
    vector<int> *adjacencyList;

public:
    void createGraph()
    {
        for (int i = 0; i < nodeCount; i++)
        {
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                graphNodes[i].insert(j);
            }
        }
    }
    Graph(int nodeCount)
    {
        this->nodeCount = nodeCount;
        adjacencyList = new vector<int>[nodeCount];
        graphNodes = new DoublyLinkedList[nodeCount];
    }
    // initialize
    void emptyAdjacencyList()
    {
        for (int i = 0; i < nodeCount; i++)
        {
            for (int j = 0; j < nodeCount; j++)
            {
                adjacencyList[i].push_back(0);
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    void printAdjacencyList()
    {
        cout << "printing adjacency list: " << endl;
        for (int i = 0; i < nodeCount; i++)
        {
            cout << i << "-> ";
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printGraph()
    {
        cout << "\nPrinting Graph: " << endl;
        for (int i = 0; i < nodeCount; i++)
        {
            cout << i << " : ";
            graphNodes[i].printList();
        }
    }

    void DeleteNode(int d)
    {
        for (int i = 0; i < nodeCount; i++)
        {
            Node *temp = graphNodes[i].head;
            if (temp->data == d)
            {
                graphNodes[i].head = NULL;
                delete (temp);
            }
            while (temp->next != NULL)
            {
                if (temp->data == d)
                {
                    // delete this node
                    Node *previous_node = temp->prev;
                    previous_node->next = temp->next;
                    temp->next = NULL;
                    delete (temp);
                }
                temp = temp->next;
            }
        }
    }

    void DFS(int start){
            bool* visited = new bool[nodeCount];
            for(int i=0;i<nodeCount;i++){
                visited[i] = false;
            }
            queue<int> q;
            q.push(start);
            visited[start] = true;
            while(!q.empty()){
                cout<<q.front()<<" ";
                DoublyLinkedList temp = graphNodes[q.front()];
                Node* head = temp.head;
                while(head!= NULL){
                    if(!visited[head->data]){
                        q.push(head->data);
                    visited[head->data] = true;
                    }
                    head = head->next;
                }
                q.pop();
            }

        }
};

int main()
{
    int n = 6, e = 15;
    Graph G(n);
    G.addEdge(0, 2);
    G.addEdge(2, 0);
    G.addEdge(0, 5);
    G.addEdge(5, 0);
    G.addEdge(0, 1);
    G.addEdge(1, 0);
    G.addEdge(1, 2);
    G.addEdge(2, 1);
    G.addEdge(2, 3);
    G.addEdge(3, 2);
    G.addEdge(2, 4);
    G.addEdge(4, 2);
    G.addEdge(4, 3);
    G.addEdge(3, 4);
    G.addEdge(5, 3);
    G.addEdge(3, 5);
    G.createGraph();
    G.printAdjacencyList();
    G.printGraph();
    cout<< "output: "<< endl;
    G.DFS(5);
    return 0;
}