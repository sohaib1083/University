#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev;
		Node *next;
	
		Node(){}
	
		Node(int data)
		{
			this -> data = data;
			this -> prev = NULL;
			this -> next = NULL;
		}
};

class DLL
{
	Node* head;
	Node* tail;
		
	public:
		DLL()
		{
			head = NULL;
			tail = NULL;
		}
		
		void print()
		{
			Node* temp = head;
			
			while (temp != NULL)
			{
				cout << temp -> data << "  ";
				temp = temp -> next;
			}
			cout << endl;
		}
		
		void insertAtHead(int d)
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
		
		void insertAtTail(int d)
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
		
		void insertAtMiddle(int d, int pos)
		{
			if (pos == 1)
			{
				insertAtHead(d);
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
				insertAtTail(d);
				return;
			}
			
			Node* curr = new Node(d);
			curr -> prev = temp;
			curr -> next = temp -> next;
			temp -> next -> prev = curr;
			temp -> next = curr;
		}
		
		void deleteNode(int pos)
		{
			Node* temp = head;
			
			if (pos == 1)
			{
				head = temp -> next;
				temp -> next -> prev = NULL;
				temp -> next = NULL;
				delete temp;
			}
			else
			{
				Node* prev = NULL;
				int count = 1;
				while(count < pos)
				{
					prev = temp;
					temp = temp -> next;
					count++;
				}
				
				temp -> prev = NULL;
				prev -> next = temp -> next;
				temp -> next = NULL;
				delete temp;
			}
		}
};

int main()
{
	return 0;
}