#include <iostream>
using namespace std;

//<----------------------------- AVL ------------------------------->

class Node
{
public:
    int data, bf;
    Node *left, *right;

    Node(int d)
    {
        left = right = NULL;
        data = d;
        bf = 0;
    }
};

class BST
{
public:
    Node *Rotate_right(Node *root)
    {
        Node *temp = root->left;
        Node *right_sub = temp->right;

        temp->right = root;
        root->left = right_sub;

        return temp;
    }

    Node *Rotate_left(Node *root)
    {
        Node *temp = root->right;
        Node *left_sub = temp->left;

        temp->left = root;
        root->right = left_sub;

        return temp;
    }

    Node *Create_Node(int d)
    {
        Node *newnode = new Node(d);
        return newnode;
    }

    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int lst = height(root->left);
        int rst = height(root->right);

        return max(lst, rst) + 1;
    }

    int balancefactor(Node *root)
    {
        return (height(root->left) - (height(root->right)));
    }

    Node *getmin(Node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }

        return root;
    }

    Node *Insert_Node(Node *root, int data)
    {
        if (root == NULL)
        {
            return Create_Node(data);
        }
        else if (data < root->data)
        {
            root->left = Insert_Node(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = Insert_Node(root->right, data);
        }

        root->bf = balancefactor(root);

        if (root->bf > 1)
        {
            if (data < root->left->data)
            {
                return Rotate_right(root);
            }
            else
            {
                root->left = Rotate_left(root->left);
                return Rotate_right(root);
            }
        }
        else if (root->bf < -1)
        {
            if (data > root->right->data)
            {
                return Rotate_left(root);
            }
            else
            {
                root->right = Rotate_right(root->right);
                return Rotate_left(root);
            }
        }

        return root;
    }

    Node *Delete_node(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        else if (key < root->data)
        {
            root->left = Delete_node(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = Delete_node(root->right, key);
        }
        else
        {
            if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else
            {
                Node *temp = getmin(root->right);
                int val = temp->data;
                root->right = Delete_node(root->right, val);
                root->data = val;
            }
        }

        if (root == NULL)
        {
            return root;
        }

        root->bf = balancefactor(root);

        if (root->bf < -1)
        {
            if (balancefactor(root->right) <= 0)
            {
                return Rotate_left(root);
            }
            else
            {
                root->right = Rotate_right(root->right);
                return Rotate_left(root);
            }
        }
        else if (root->bf > 1)
        {
            if (balancefactor(root->left) >= 0)
            {
                return Rotate_right(root);
            }
            else
            {
                root->left = Rotate_left(root->left);
                return Rotate_right(root);
            }
        }

        return root;
    }
};

//<----------------------------- HEAP ------------------------------->

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    int size = n - 1;

    while (size > 0)
    {
        // step 1
        swap(arr[0], arr[size]);
        size--;
        // step 2
        heapify(arr, size, 0);
    }
}

void BuildHeap(int arr[], int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

//<----------------------------- STACK ------------------------------->

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//<----------------------------- QUEUE ------------------------------->
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            // cout << "Queue is Full";
            return false;
        }
        else if (front == -1) // first element
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        {
            rear++;
        }
        arr[rear] = value;

        return true;
    }

    int dequeue()
    {
        if (front == -1)
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        {
            front++;
        }
        return ans;
    }
};

//<----------------------------- DOUBLE ENDED QUEUE ------------------------------->

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        // check full or not
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
        {
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if (isEmpty())
        {
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//<----------------------------- INFIX TO POSTFIX ------------------------------->

#include <stack>

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                    {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

//<----------------------------- QUICK SORT ------------------------------->

int partition(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int pivot = arr[mid];
    int pivot_pos = mid;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[pivot_pos], arr[end]);
    return end;
}

void quickSort(int *arr, int lb, int ub)
{
    int return_val;
    // divide () & conquer ()
    if (lb < ub)
    {
        return_val = partition(arr, lb, ub);
        quickSort(arr, return_val + 1, ub);
        quickSort(arr, lb, return_val - 1);
    }
}

//<----------------------------- RADIX SORT ------------------------------->

int FindMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int size, int pos)
{
    int count[10] = {0};
    int output[10] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    // cumulative
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int size)
{
    int max = FindMax(arr, size);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countSort(arr, size, pos);
    }
}

//<----------------------------- MERGE SORT ------------------------------->

void merge(int arr[], int l, int mid, int r)
{

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *a = new int[n1];
    int *b = new int[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

//<----------------------------- LEVEL ORDER TRAVERSAL ------------------------------->

#include <queue>

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//<----------------------------- IS VALID BST ------------------------------->
#include <vector>

void storeinorder(Node *root, vector<int> *temp)
{
    if (root != NULL)
    {
        storeinorder(root->left, temp);
        temp->push_back(root->data);
        storeinorder(root->right, temp);
    }
}

bool isValidBST(Node *root)
{
    vector<int> temp;
    storeinorder(root, &temp);
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] >= temp[i + 1])
            return false;
    }
    return true;
}

//<----------------------------- DELETE IN A BST ------------------------------->

int minval(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        // no child
        if (root->right == NULL && root->left == NULL)
        {
            delete (root);
            return NULL;
        }

        // 1 left child
        if (root->right == NULL && root->left != NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }

        // 1 right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }

        // both child
        if (root->left != NULL && root->right != NULL)
        {
            // inorder successor
            int min = minval(root->right);
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else
    {
        if (key > root->data)
        {

            root->right = deleteNode(root->right, key);
        }
        else
        {

            root->left = deleteNode(root->left, key);
        }
    }

    return root;
}

//<----------------------------- INSERT IN A BST ------------------------------->

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
    {
        Node *newnode = new Node(val);
        return newnode;
    }
    else
    {
        if (val > root->data)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else if (val < root->data)
        {
            root->left = insertIntoBST(root->left, val);
        }
    }
    return root;
}

//<----------------------------- GRAPHS ------------------------------->
//<----------------------------- BFS ------------------------------->

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

//<----------------------------- PRIMS ------------------------------->

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
    int min = INT_MAX, min_index = -1;

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
            if (graph[u][v] != 0 && includedMST[v] == false && graph[u][v] < minEdgeCut[v])
            {
                parent[v] = u;
                minEdgeCut[v] = graph[u][v];
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 1; i < n; i++)
    {
        result.push_back({{parent[i] + 1, i + 1}, minEdgeCut[i]});
    }

    return result;
}

//<----------------------------- DJIKSTRAS ------------------------------->

#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

int minDistance(vector<int> distance, vector<bool> visited, int vertices)
{
    int min = INT_MAX, minVertex;

    for (int v = 0; v < vertices; v++)
    {
        if (visited[v] == false && distance[v] <= min)
        {
            min = distance[v];
            minVertex = v;
        }
    }
    return minVertex;
}

vector<int> dijkstraHelper(vector<vector<int>> &matrix, int vertices, int source)
{
    vector<int> distance(vertices, INT_MAX);
    vector<bool> visited(vertices, false);

    // Distance of source to itself is 0.
    distance[source] = 0;

    for (int i = 0; i < vertices; i++)
    {

        int u = minDistance(distance, visited, vertices);

        // visited
        visited[u] = true;

        // Update the distances
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && matrix[u][v] && distance[u] != INT_MAX && distance[u] + matrix[u][v] < distance[v])
            {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
    }
    return distance;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));

    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        if (matrix[u][v] != 0)
        {
            matrix[u][v] = min(matrix[u][v], w);
            matrix[v][u] = min(matrix[v][u], w);
        }
        else
        {
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
    }
    return dijkstraHelper(matrix, vertices, source);
}

//<----------------------------- HUFFMAN ------------------------------->

#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct node
{
    int freq;
    char data;
    const node *child0, *child1;
    node(char d, int f = -1)
    {
        data = d;
        freq = f;
        child0 = NULL;
        child1 = NULL;
    }
    node(const node *c0, const node *c1)
    {
        data = 0;
        freq = c0->freq + c1->freq;
        child0 = c0;
        child1 = c1;
    }
    bool operator<(const node &a) const
    {
        return freq > a.freq;
    }
    void traverse(string code = "") const
    {
        if (child0 != NULL)
        {
            child0->traverse(code + '0');
            child1->traverse(code + '1');
        }
        else
        {
            cout << "Data: " << data << ", Frequency: " << freq << ", Code: " << code << endl;
        }
    }
};
void huffmanCoding(string str)
{
    priority_queue<node> qu;
    int frequency[256];
    for (int i = 0; i < 256; i++)
        frequency[i] = 0;
    for (int i = 0; i < str.size(); i++)
    {
        frequency[int(str[i])]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (frequency[i])
        {
            qu.push(node(i, frequency[i]));
        }
    }
    while (qu.size() > 1)
    {
        node *c0 = new node(qu.top());
        qu.pop();
        node *c1 = new node(qu.top());
        qu.pop();
        qu.push(node(c0, c1));
    }
    cout << "The Huffman Code: " << endl;
    qu.top().traverse();
}

//<----------------------------- HASHING ------------------------------->

#include <iostream>
using namespace std;
#define size 10

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashMapTable
{
private:
    HashNode **t;

public:
    HashMapTable()
    {
        t = new HashNode *[size];
        for (int i = 0; i < size; i++)
            t[i] = NULL;
    }

    int HashFunc(int k)
    {
        return (k % size);
    }
    void Insert(int k, int v)
    {
        int index = HashFunc(k);
        HashNode *newEntry = new HashNode(k, v);

        if (t[index] == NULL)
        {
            t[index] = newEntry;
            cout << "value added" << endl;
            return;
        }

        HashNode *temp;
        temp = t[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEntry;
        return;
    }
    int SearchKey(int k)
    {
        int index = HashFunc(k);
        for (int i = 0; i < size; i++)
        {
            if (t[index]->key == k)
                return index;

            HashNode *temp = t[index];

            while (temp != NULL)
            {
                if (temp->key == k)
                {
                    return index;
                }
                temp = temp->next;
            }
        }

        return -1;
    }
    void Remove(int k)
    {
        int pos = SearchKey(k);

        if (pos == -1)
        {
            cout << "Value not found";
            return;
        }

        if (t[pos]->key == k)
        {
            t[pos] = t[pos]->next;
            return;
        }

        HashNode *first = t[pos];
        HashNode *second = t[pos]->next;

        while (second != NULL)
        {
            if (second->key == k)
            {
                first->next = second->next;
                delete (second);
                second = NULL;
                return;
                // delete
            }
            first = second;
            second = second->next;
        }
    }

    void traverse()
    {
        cout << "K      V" << endl;
        for (int i = 0; i < size; i++)
        {
            if (t[i] != NULL)
            {
                HashNode *temp = t[i];
                while (temp != NULL)
                {
                    cout << temp->key << "--->" << temp->value << endl;
                    temp = temp->next;
                }
            }
        }
    }

    ~HashMapTable()
    {
        delete[] t;
        t = NULL;
    }
};

//<----------------------------- DFS ------------------------------->

    // void DFS(int start){
    //         bool* visited = new bool[nodeCount];
    //         for(int i=0;i<nodeCount;i++){
    //             visited[i] = false;
    //         }
    //         queue<int> q;
    //         q.push(start);
    //         visited[start] = true;
    //         while(!q.empty()){
    //             cout<<q.front()<<" ";
    //             DoublyLinkedList temp = graphNodes[q.front()];
    //             Node* head = temp.head;
    //             while(head!= NULL){
    //                 if(!visited[head->data]){
    //                     q.push(head->data);
    //                 visited[head->data] = true;
    //                 }
    //                 head = head->next;
    //             }
    //             q.pop();
    //         }

    //     }

int main (void)
{
    return 0;
}
