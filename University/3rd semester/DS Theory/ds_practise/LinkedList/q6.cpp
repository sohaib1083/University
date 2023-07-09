#include <iostream>

template <typename T>
void InsertAtMiddle(Node<T>* rhs) {
  // Check if the circular linked list is empty
  if (!rhs) return;

  // Check if the circular linked list has only one node
  if (!rhs->next) {
    rhs->next = rhs;
    return;
  }

  // Initialize two pointers, fast and slow, to the head of the list
  Node<T>* fast = rhs;
  Node<T>* slow = rhs;

  // Move the fast pointer twice as fast as the slow pointer
  fast = fast->next;
  if (fast->next) fast = fast->next;
  else {
    // If the fast pointer is at the end of the list, insert the node at the beginning
    rhs->next = new Node<T>(rhs->val, rhs->next);
    rhs->val = rhs->next->val;
    rhs->next->val = rhs->val;
    return;
  }

  // Move both pointers until the fast pointer reaches the end of the list
  while (fast->next) {
    fast = fast->next;
    if (fast->next) fast = fast->next;
    slow = slow->next;
  }

  // Insert the node after the slow pointer
  slow->next = new Node<T>(rhs->val, slow->next);
};
