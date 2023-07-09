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

class Circular_DLL
{
	Node* head;
	Node* tail;
		
	public:
		Circular_DLL()
		{
			head = NULL;
			tail = NULL;
		}
		
		void print()
		{
			Node* temp = head;
			
            do
			{
				cout << temp -> data << "  ";
				temp = temp -> next;
			} while (temp != head);
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
				temp -> prev = tail;
				head = temp;
                tail->next = head;
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
				temp -> next = head;
				tail = temp;
                head->prev = tail;
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
				temp -> next -> prev = tail;
                tail->next = head;
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
	Circular_DLL node1;
	node1.insertAtHead(10);			//  10
	node1.insertAtHead(15);			//  15  10
	node1.insertAtTail(12);			//  15  10  12
	node1.insertAtTail(14);			//  15  10  12  14
	node1.insertAtTail(16);			//  15  10  12  14  16
	node1.insertAtTail(18);			//  15  10  12  14  16  18
	node1.insertAtMiddle(42, 3);	//  15  10  42  12  14  16  18
	node1.deleteNode(6);			//  15  10  42  12  14  18
	node1.print();
	return 0;
}