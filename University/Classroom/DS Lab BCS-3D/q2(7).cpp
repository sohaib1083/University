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
    LinkedList(node *n){head=n;}

    void PrintLL()
    {
        node *temp=head;

        while(temp !=NULL)
        {
            cout<< temp->data<< " ";
            temp=temp->next;
        }
    }
    void AppendNode(int new_data)
    { 
            node *newNode = new node(new_data); 
		    if (head == NULL) 
            { 
			    head = newNode;
			    return; 
            } 
		// if not the head node traverse the list and add it to the last
		    node *last = head;
		    while (last->next != NULL)
			    last = last->next;
		    last->next = newNode;
		    // return;
	}
 };

int main (void)
{
    node * n1 = new node (10);
    node *n2 = new node (20);
    LinkedList l1(n1);
    l1.PrintLL();
    cout<< endl;
    l1.AppendNode(120);
    l1.AppendNode(34);
    l1.PrintLL();   
    return 0;
}