#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node * next;
    node * prev;

    node (int d)
    {
        data = d;
        next =NULL;
        prev = NULL;
    }
};

class Doubly_LL{
    public:
    node * head;
    node * tail;

    Doubly_LL()
    {
        head = NULL;
    }

    void append (int d)
    {
        node * newNode = new node(d);
        node * temp = head;

        if (head == NULL)
        {
            head = newNode;
        }
        else{
             while (temp->next != NULL)
             {
                temp = temp->next;
             }
             temp->next = newNode;
             newNode->prev = temp;
        }
    }

    void print ()
    {
        node * temp = head;
        while (temp != NULL)
        {
            cout<< temp->data<< " ";
            temp= temp->next;
        }
        cout<< endl;
    }

};

void concat (Doubly_LL &L, Doubly_LL &M)
{
    node * L_head = L.head;
    node * M_head = M.head;

    while (L_head->next != NULL)
    {
        L_head = L_head->next;
    }
    L_head->next = M_head;
    M_head->prev = L_head;
    while (M_head ->next != NULL)
    {
        L_head=L_head->next;
        M_head=M_head->next;
        L_head->next = M_head;
        M_head->prev = L_head;
    }
}

int main (void)
{
    Doubly_LL L;
    L.append(3);
    L.append(2);
    L.append(6);
    L.print();

    Doubly_LL M;
    M.append(7);
    M.append(1);
    M.append(5);
    M.print();

    concat(L, M);
    L.print();
    return 0;
}