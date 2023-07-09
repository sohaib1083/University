#include <iostream>

struct Node {
  int val;
  Node* next;
  Node(int v) : val(v), next(nullptr) {}
};

Node* mergeLists(Node* head1, Node* head2) {
  // If one of the lists is empty, return the other list
  if (!head1) return head2;
  if (!head2) return head1;

  // Initialize a dummy node
  Node* dummy = new Node(0);
  Node* curr = dummy;

  // Iterate through both lists, adding the smaller value to the merged list
  while (head1 && head2) {
    if (head1->val < head2->val) {
      curr->next = head1;
      head1 = head1->next;
    } else {
      curr->next = head2;
      head2 = head2->next;
    }
    curr = curr->next;
  }

  // Add the remaining elements of the non-empty list
  if (head1) curr->next = head1;
  if (head2) curr->next = head2;

  // Return the merged list, starting at the dummy node's next element
  Node* res = dummy->next;
  delete dummy;
  return res;
}

int main() {
  Node* head1 = new Node(1);
  head1->next = new Node(3);
  head1->next->next = new Node(5);

  Node* head2 = new Node(2);
  head2->next = new Node(4);
  head2->next->next = new Node(6);

  Node* merged = mergeLists(head1, head2);

  // Print out the merged list
  Node* curr = merged;
  while (curr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }

  return 0;
}
