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
    int size()
    {
        int count = 0;
        node * temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    void modify ()
    {
        int size_of_list = size();
        int num_of_evens=0, num_of_odd=0;
        node * temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                num_of_evens++;
            }
            else
            {
                num_of_odd++;
            }
            temp = temp->next;           
        }
        if (num_of_evens == size_of_list || num_of_odd == size_of_list)
        {
            return;
        }
        else
        {
            //sort - even num first then odd - kind of selection sort cuz of min swaps
            node * start=head, *end;
            for (int i=0; i<size_of_list; i++)
            {
                for (int j=i; j<size_of_list; j++)
                {
                    end = start;
                    while (end !=NULL)
                    {
                        if (end->data % 2 == 0)
                        {
                            int swap = end->data;
                            end->data=start->data;
                            start->data = swap;
                            break;
                        }
                    end = end->next;
                    }
                }
                start = start->next;
            }

        }
    }
 };



int main (void)
{
    node * n1 = new node (5);
    node *n2 = new node (20);
    LinkedList l1(n1);
    l1.PrintLL();
    cout<< endl;
    l1.AppendNode(7);
    l1.AppendNode(10);
    l1.AppendNode(8);
    l1.AppendNode(12);
    l1.PrintLL();
    cout<< endl;

    l1.modify();
    l1.PrintLL();
    cout<< endl;
    // l1.insertAfterNode(1, 89);   
    // l1.PrintLL();
    // cout<< endl;
    // l1.deleteNode(2);
    // l1.PrintLL();
    // cout<< endl;
    // l1.UpdateNode(3, 60);
    // l1.PrintLL();
    return 0;
}