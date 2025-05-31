#include <iostream>

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
// two elements whose sum is equal to the given number
bool sum_exists(int arr[], int n, int x)
{
  // create a hash table
  HashTable ht;

  // insert all the elements of the array into the hash table
  for (int i = 0; i < n; i++)
    ht.insert(arr[i]);

  // search for the complement of each element in the hash table
  for (int i = 0; i < n; i++)
  {
    int complement = x - arr[i];
    if (ht.search(complement))
      return true;
  }

  // elements not found
  return false;
}

int main()
{
  int arr[] = {1, 4, 45, 6, 10, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 16;

  if (sum_exists(arr, n, x))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
