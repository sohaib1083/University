#include <iostream>
#include <vector>

using namespace std;

// node of the singly linked list
struct Node
{
  int data;
  Node* next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

// hash table with chaining using singly linked list
const int TABLE_SIZE = 1000;

class HashTable
{
private:
  // array of pointers to nodes
  Node** table;

public:
  HashTable()
  {
    // allocate memory for the table
    table = new Node*[TABLE_SIZE]();
  }

  // hash function
  int hash(int key)
  {
    return key % TABLE_SIZE;
  }

  // function to insert a new key-value pair into the hash table
  void insert(int key)
  {
    // create a new node
    Node* newNode = new Node(key);

    // get the index for the key
    int index = hash(key);

    // add the new node at the beginning of the list
    newNode->next = table[index];
    table[index] = newNode;
  }

  // function to search for a key in the hash table
  bool search(int key)
  {
    // get the index for the key
    int index = hash(key);

    // search the list at the given index
    Node* temp = table[index];
    while (temp)
    {
      if (temp->data == key)
        return true;
      temp = temp->next;
    }

    // key not found
    return false;
  }
};

// function to check if the given array contains
// a triplet that sums up to zero
bool triplet_sum_zero(int arr[], int n)
{
  // create a hash table
  HashTable ht;

  // insert all the elements of the array into the hash table
  for (int i = 0; i < n; i++)
    ht.insert(arr[i]);

  // fix the first element of the triplet
  for (int i = 0; i < n; i++)
  {
    // fix the second element of the triplet
    for (int j = i + 1; j < n; j++)
    {
      // check if the third element of the triplet
      // is present in the hash table
      if (ht.search(-arr[i] - arr[j]))
        return true;
    }
  }

  // triplet not found
  return false;
}

int main()
{
  int arr[] = {0, -1, 2, -3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  if (triplet_sum_zero(arr, n))
    cout << "Triplet found" << endl;
  else
    cout << "Triplet not found" << endl;

  return 0;
}
