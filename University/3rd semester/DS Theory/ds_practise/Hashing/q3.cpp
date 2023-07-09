#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int value, Node* next=nullptr) : value(value), next(next) {}
};

int first_repeating_element(int arr[], int n) {
    Node** hashtable= new Node * [n]();

    // Initialize the hashtable
    for (int i = 0; i < n; i++) {
        hashtable[i] = nullptr;
    }

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        // Calculate the hash value of x
        int hash_value = hash<int>()(x) % n;

        // Check if x is present in the hashtable
        if (hashtable[hash_value] == nullptr) {
            // If not, add it to the hashtable
            hashtable[hash_value] = new Node(x);
        } else {
            // If x is present, traverse the linked list at the calculated index
            // to check if x is present
            Node* curr = hashtable[hash_value];
            while (curr != nullptr) {
                if (curr->value == x) {
                    // If x is present, return the index of the first occurrence
                    return i + 1;
                }
                curr = curr->next;
            }
            // If x is not present in the linked list, add it to the list
            curr = hashtable[hash_value];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(x);
        }
    }

    // If no repeating elements are found, return -1
    return -1;
}

int main() {
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << first_repeating_element(arr, n) << endl;  // Output: 2
    return 0;
}
