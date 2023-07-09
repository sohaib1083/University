#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
	
		node(){ data=0; }
	
		node(int data)
		{
			this -> data = data;
			this -> next = NULL;
		}
		
		~node()
		{
            // destructor
		}
};

class circular_LL{
	public:
	node * head;

	circular_LL() { head = NULL;}

	void Append_node(int data)
	{
		node * newNode = new node(data);
		node * temp = head;

		if (temp == NULL)
		{
			head = newNode;
			newNode->next = head;
		}
		else{
			while(temp->next != head)
			{
				temp= temp->next;
			}

			temp->next = newNode;
			newNode->next = head;
		}
	}

	void prependNode (int data)
	{
		node * temp = head;
		node * newNode = new node(data);
		if (temp == NULL)
		{
			head = newNode;
			newNode->next = head;
		}
		else{
			while (temp->next != head)
			{
				temp = temp->next;
			}

			newNode->next = head;
			head = newNode;
			temp->next = head;
		}
	}

	void insertAfterNode (int d, int pos)
	{
		node * temp = head;
		node * newNode = new node (d);
		int count =1;
		while (count<pos)
		{
			temp = temp->next;
			count++;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}

	void deleteNode(int pos)
	{
		node * prev= head;
		node * temp = head->next;
		int count =1;

		while (count<pos-1)
		{
			prev = prev->next;
			temp=temp->next;
			count++;
		}
		prev->next = temp->next;
		delete (temp);

	}

	void print ()
	{
		node * temp = head;

		do
		{
			cout<< temp->data<< " ";
			temp = temp->next;
		} while (temp != head);
	}
};


int main()
{
	node* node1 = new node(3);

	circular_LL A;
	A.Append_node(5);
	A.Append_node(6);
	A.Append_node(2);
	A.Append_node(3);
	A.print();
	cout<< endl;
	A.prependNode(7);
	A.prependNode(8);
	A.print();
	cout<< endl;
	A.insertAfterNode(23, 3);
	A.print();
	cout<< endl;
	A.deleteNode(3);
	A.print();
	return 0;
}
