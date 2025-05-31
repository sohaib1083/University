#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
};

// Function to determine whether a linked list is a palindrome
bool isPalindrome(Node* head) {
    // Step 1: Use slow and fast pointers to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    std::stack<int> secondHalf;
    while (slow != nullptr) {
        secondHalf.push(slow->data);
        slow = slow->next;
    }

    // Step 3: Compare the first half of the linked list with the reversed second half
    Node* current = head;
    while (!secondHalf.empty()) {
        if (current->data != secondHalf.top()) {
            return false;
        }
        current = current->next;
        secondHalf.pop();
    }
    return true;
}

int main() {
    // Create a palindromic linked list:
    // 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node{1, nullptr};
    Node* current = head;
    for (int i = 2; i <= 3; i++) {
        current->next = new Node{i, nullptr};
        current = current->next;
    }
    current->next = new Node{2, new Node{1, nullptr}};

    // Print whether the linked list is a palindrome
    std::cout << std::boolalpha << isPalindrome(head) << std::endl;

    return 0;
}
