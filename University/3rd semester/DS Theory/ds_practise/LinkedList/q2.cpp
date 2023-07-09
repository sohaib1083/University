#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to remove the middle node of a linked list
void removeMiddleNode(Node* head) {
    // Step 1: Determine the length of the linked list
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    // Step 2: Find the middle node
    int middleIndex = length / 2;

    // Step 3: Traverse to the node before the middle node
    current = head;
    for (int i = 0; i < middleIndex - 1; i++) {
        current = current->next;
    }

    // Step 4: Update the next pointer of the node before the middle node
    // to skip the middle node and point directly to the node after the middle node
    current->next = current->next->next;
}

int main() {
    // Create a linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    Node* current = head;
    for (int i = 2; i <= 5; i++) {
        current->next = new Node{i, nullptr};
        current = current->next;
    }

    // Remove the middle node (3)
    removeMiddleNode(head);

    // Print the modified linked list
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
