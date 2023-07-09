#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev;
		Node *next;
	
		Node(){ next=NULL; }
	
		Node(int data)
		{
			this -> data = data;
			this -> prev = NULL;
			this -> next = NULL;
		}
		
		~Node()
		{
			if (this -> next != NULL)
			{
				delete next;
				this -> next = NULL;
			}
		}
};

void print(Node* head)
{
	Node* temp = head;
	
	while (temp != NULL)
	{
		cout << temp -> data << "  ";
		temp = temp -> next;
	}
	cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int d)
{
	Node* temp = new Node(d);
	
	if (head == NULL) //In case of empty LL
	{
		head = temp;
		tail = temp;
	}
	else
	{
		head -> prev = temp;
		temp -> next = head;
		temp -> prev = NULL;
		head = temp;
	}
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
	Node* temp = new Node(d);
	
	if (head == NULL) //In case of empty LL
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail -> next = temp;
		temp -> prev = tail;
		temp -> next = NULL;
		tail = temp;
	}
}

void insertAtMiddle(Node* &head, Node* &tail, int d, int pos)
{
	if (pos == 1)
	{
		insertAtHead(head, tail, d);
		return;
	}
	
	Node* temp = head;
	int count = 1;
	while (count < pos - 1)
	{
		temp = temp -> next;
		count++;
	}
	
	if (temp -> next == NULL)
	{
		insertAtTail(head, tail, d);
		return;
	}
	
	Node* curr = new Node(d);
	curr -> prev = temp;
	curr -> next = temp -> next;
	temp -> next -> prev = curr;
	temp -> next = curr;
}

int size_of_LL (Node* &head)
{
    Node * temp = head;
    int count=1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteNode(Node* &head, Node* &tail, int pos)
{
	Node* temp = head;
	
	if (pos == 1)
	{
		head = temp -> next;
		head -> prev = NULL;
		temp -> next = NULL;
		delete temp;
        return;
	}
    
    if (pos == size_of_LL(head))
    {
        // last 
        Node * temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        return;
    }
		int count = 1;
		while(count < pos)
		{
			temp = temp -> next;
			count++;
		}
        temp->data;
		Node * currentNode = temp->prev;
        currentNode->next = temp->next;
        temp->next->prev = currentNode;
        temp->next =NULL;
        temp->prev =NULL;
        delete(temp);
}

int main()
{
	Node* node1 = new Node(3);
	Node* head = node1;
	Node* tail = node1;
	insertAtHead(head, tail, 7);
	insertAtHead(head, tail, 9);
	insertAtTail(head, tail, 10);
	insertAtTail(head, tail, 15);
	insertAtTail(head, tail, 18);
	insertAtTail(head, tail, 16);
	insertAtMiddle(head, tail, 42, 3);
	deleteNode(head, tail, 5);
	print(head);
	return 0;
}
