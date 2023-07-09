#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    // Edge case: empty or single-element list
    if (!head || !head->next) return;

    // Find the middle element of the list
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *prev = slow, *curr = slow->next;
    while (curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // Merge the two halves of the list
    ListNode *first = head, *second = prev;
    while (second->next) {
        ListNode *first_next = first->next;
        ListNode *second_next = second->next;
        first->next = second;
        second->next = first_next;
        first = first_next;
        second = second_next;
    }

    // Set the next pointer of the last element of the first half to nullptr
    first->next = nullptr;
}

int main() {
    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Reorder the linked list
    reorderList(head);

    // Print the reordered linked list
    ListNode *node = head;
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;

    return 0;
}
