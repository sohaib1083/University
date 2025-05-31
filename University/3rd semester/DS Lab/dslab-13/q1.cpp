#include <iostream>
#include <vector>
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

public:
    Graph(int nodeCount)
    {
        this->nodeCount = nodeCount;
        adjacencyList = new vector<int>[nodeCount];
        graphNodes = new DoublyLinkedList[nodeCount];
    }
    void emptyAdjacencyList()
    {
        // initialise
        for (int i = 0; i < nodeCount; i++)
        {
            for (int j = 0; j < nodeCount; j++)
            {
                adjacencyList[i].push_back(0);
            }
        }
    }
    void inputAdjacencyList()
    {
        int num1;
        int num2;
        
        cout << "Enter -999 to cancel: " << endl;
        cout << "Enter edges (u v): ";
        while (true)
        {
            cin >> num1;
            if (num1 == -999)
            {
                break;
            }
            cin >> num2;
            adjacencyList[num1].push_back(num2);
        }
        createGraph();
    }
    void printAdjacencyList()
    {
        for (int i = 0; i < nodeCount; i++)
        {
            for (int j = 0; j < adjacencyList[i].size(); j++)
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < nodeCount; i++)
        {
            cout << i << " --> ";
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
};

int main(void)
{
    int n;
    cout << "Enter the number of edges: ";
    cin >> n;
    Graph G(n);
    G.inputAdjacencyList();
    G.printAdjacencyList();
    G.printGraph();
    int ex = 2;
    G.DeleteNode(ex);
    G.printGraph();
    return 0;
}