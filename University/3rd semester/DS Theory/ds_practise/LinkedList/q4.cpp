#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to eliminate nodes from a doubly linked list
void eliminateNodes(Node* head) {
    // Initialize pointers to the head of the linked list
    Node* left = head;
    Node* right = head;

    // While left and right are not null
    while (left != nullptr && right != nullptr) {
        // Remove the first element by setting left to left->next
        left = left->next;

        // Remove the last element by setting right to right->prev
        right = right->prev;
    }

    // If left is not null, remove all the remaining elements
    // by setting the next pointer of left->prev to null
    if (left != nullptr) {
        left->prev->next = nullptr;
    }

    // If right is not null, remove all the remaining elements
    // by setting the prev pointer of right->next to null
    if (right != nullptr) {
        right->next->prev = nullptr;
    }
}

int main() {
    // Create a doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9
    Node* head = new Node{1, nullptr, nullptr};
    Node* current = head;
    for (int i = 2; i <= 9; i++) {
        current->next = new Node{i, current, nullptr};
        current = current->next;
    }

    // Eliminate nodes from the linked list
    eliminateNodes(head);

    // Print the modified linked list
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
