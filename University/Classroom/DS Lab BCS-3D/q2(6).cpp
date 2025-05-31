#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
	
		Node(){ data=0; }
	
		Node(int data)
		{
			this -> data = data;
			this -> next = NULL;
		}
		
		~Node()
		{
            // destructor
		}
};

void print(Node* &head)
{
	Node* temp = head;
	
	while (temp != head)
	{
		cout << temp -> data << "  ";
		temp = temp -> next;
	}
	cout << endl;
}

void insertAtHead(Node* &head, int d)
{
	Node* newNode = new Node(d);

	if (head == NULL) //In case of empty LL
	{
		head = newNode;
        newNode->next = newNode;
	}
	else
	{ 
	    Node * end = head;
        // traverse
        while (end->next != head)
        {
            end = end->next;
        }

		newNode->next = end->next;
		head = newNode;
		end->next = head;
	}
}


int main()
{
	Node* node1 = new Node(3);
	Node* head= node1;
	insertAtHead(head, 7);
	insertAtHead(head, 9);	
	print(head);
	return 0;
}
