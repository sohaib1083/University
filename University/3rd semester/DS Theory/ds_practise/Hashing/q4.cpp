#include <iostream>
#include <unordered_map>

using namespace std;

const int P = 1000; // maximum value for element in the array

struct Node {
  int key;
  int value;
  Node* next;
};

class HashTable {
private:
  Node* table[P]; // hash table
  int size; // number of elements in the hash table

public:
  HashTable() {
    // initialize the hash table
    for (int i = 0; i < P; i++) {
      table[i] = nullptr;
    }
    size = 0;
  }

  ~HashTable() {
    // deallocate memory used by the hash table
    for (int i = 0; i < P; i++) {
      Node* node = table[i];
      while (node != nullptr) {
        Node* next = node->next;
        delete node;
        node = next;
      }
    }
  }

  int hash(int key) {
    // hash function to map the key to an index in the hash table
    return key % P;
  }

  void insert(int key, int value) {
    // insert the key-value pair into the hash table
    int index = hash(key);
    Node* node = new Node();
    node->key = key;
    node->value = value;
    node->next = table[index];
    table[index] = node;
    size++;
  }

  int find(int key) {
    // find the value associated with the given key in the hash table
    int index = hash(key);
    Node* node = table[index];
    while (node != nullptr && node->key != key) {
      node = node->next;
    }
    if (node == nullptr) {
      // key not found
      return -1;
    } else {
      // key found
      return node->value;
    }
  }
};

int main() {
int N = 5;
  int A[5];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int P;
  cin >> P;

  HashTable hashTable;

  // count the frequency of each element from 1 to N
  for (int i = 0; i < N; i++) {
    if (A[i] <= N) {
      int value = hashTable.find(A[i]);
      if (value == -1) {
        // element not found, insert it with a frequency of 1
        hashTable.insert(A[i], 1);
      } else {
        // element found, increment its frequency
        hashTable.insert(A[i], value + 1);
      }
    }
  }

  // print the frequency of each element
  for (int i = 1; i <= N; i++) {
    int value = hashTable.find(i);
    if (value == -1) {
      // element not found, frequency is 0
      cout << 0 << " ";
    }
  }
}  