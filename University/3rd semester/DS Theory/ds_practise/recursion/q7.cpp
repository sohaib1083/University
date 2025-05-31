#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *reverse(Node * curr, Node * prev)
{
    // base case
    if (curr == NULL){
        return prev;
    }

    Node * forward = curr->next;
    return reverse(forward, curr);
    curr = curr->next;
    
    
}

int main(void)
{
    Node *head;// create the linked list here
    Node *rev = reverse(head, nullptr);
}