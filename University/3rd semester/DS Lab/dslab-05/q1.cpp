#include<iostream>
using namespace std;

class node{
    public:
    int key;
    int data;
    node * next;
    node * ptr;
    node (){data=0; next=NULL;}
    node (int data){this->data=data; next=NULL;}
};

class LinkedList{
    public:
    node *head;
    LinkedList(){head=NULL;}
    LinkedList(node *NewNode){head = NewNode;}
};

int main (void)
{
    node * n1 = new node (10);
    LinkedList *l1 = new LinkedList (n1);
    return 0;
}