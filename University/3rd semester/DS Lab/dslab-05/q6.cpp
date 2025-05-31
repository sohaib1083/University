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

    void push(int new_data){
   		node *newNode = new node(new_data);
  		newNode->next = head;
		head = newNode;
	}

    void insertAfterNode (int pos, int new_data)
    {
        if(pos == 1)
        {
            push(new_data);
            return;
        }
        int cnt=1;
        node * newNode = new node (new_data);
        node * temp = head;
        while (cnt < pos-1)
        {
            temp = temp->next;
            cnt++;
            cout<< cnt<< endl;
        }

        newNode ->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode (int pos)
    {
        
        node * temp = head;
        node * prev;
        int cnt =1;

        if (pos ==1)
        {
            head= head->next;
            temp->next=NULL;
            delete(temp);
        }

        while (temp!=NULL && (cnt < pos))
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        prev->next = temp->next;
        temp->next= NULL;
        delete(temp);
    }

    void UpdateNode (int pos, int new_data)
    {
        node * temp = head;
        int cnt =1;
        while (cnt<pos)
        {
            temp = temp->next;
            cnt++;
        }
        temp->data=new_data;
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
    cout<< endl;
    l1.insertAfterNode(1, 89);   
    l1.PrintLL();
    cout<< endl;
    l1.deleteNode(2);
    l1.PrintLL();
    cout<< endl;
    l1.UpdateNode(3, 60);
    l1.PrintLL();
    return 0;
}