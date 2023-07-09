#include <bits/stdc++.h>
using namespace std;

#define SIZE 3

class Node
{
    public:
        pair<char, pair<int,int>> data;
        Node *next;

        Node(pair<char, pair<int,int>> d)
        {
            data = d;
            next = NULL;
        }
};

class Circular_Linked_List
{
    public:
        Node *head;

        Circular_Linked_List()
        { 
            head = NULL;
        }

        int count_nodes()
        {
            Node *temp = head;
            int count=0;
            while (temp != NULL)
            {
                temp = temp->next;
                count++;
            }
            return count;
        }

        void Append_Node(pair<char, pair<int,int>> data)
        {
            Node *newnode = new Node(data), *temp = head;

            if(temp == NULL)
            {
                head = newnode;
                newnode->next = head;
            }
            else
            {
                while(temp->next != head)
                {
                    temp = temp->next;
                }

                temp->next = newnode;
                newnode->next = head;   
            }
        }

        bool Search(char d)
        {
            Node *temp = head;
            while(temp != NULL)
            {
                if(temp->data.first == d)
                {
                    return true;
                }
            }
            return false;
        }

        

        void delete_node(char pos)
        {
            Node *temp = head;

            while(temp->next != head)
            {
                if(temp->next->data.first == pos)
                {
                    break;
                }
                temp = temp->next;
            }

            if(temp->next == NULL)
            {
                cout << "No node";
            }
            else
            {
                Node *del = temp->next;
                
                temp->next = temp->next->next;
                delete del;
            }   
        }

        char remove()
        {
            Node *temp = head;

            while(temp != NULL)
            {
                if(temp->data.second.first == 0 && temp->data.second.second == 0){return temp->data.first;}
                temp = temp->next;
            }
            temp = head;
            while(temp != NULL)
            {
                if(temp->data.second.first == 0 && temp->data.second.second == 1){return temp->data.first;}
                temp = temp->next;
            }
            temp = head;
            while(temp != NULL)
            {
                if(temp->data.second.first > 0){temp->data.second.first--;}
                temp = temp->next;
            }
            return 'E'; 
        }

        void update(char s, int s1, int s2)
        {
            Node *temp = head;
            while(temp != NULL)
            {
                if(temp->data.first == s)
                {
                    break;
                }
                temp = temp->next;
            }
            temp->data.second.first = s1;
            temp->data.second.second = s2;
        }

        // void print()
        // {
        //     Node *temp = head;

        //     do
        //     {
        //         cout << temp->data << " -> ";
        //         temp = temp->next;
        //     }while(temp != head);
        // }
};


int main()
{
     string ref = "01362452502312524";
    string modified = "YNNNNYNNYNNNYNYNN";


    Circular_Linked_List ll;


    for(int i=0; i<ref.size(); i++)
    {
        bool check = ll.Search(ref[i]);

        if(check == false)
        {
            int nodes = ll.count_nodes();
            if(nodes < SIZE)
            {
                if(modified[i] == 'Y'){ll.Append_Node(make_pair(ref[i], make_pair(1,1)));}
                else{ll.Append_Node(make_pair(ref[i], make_pair(1,0)));}

            }
            else
            {
                char remove = ll.remove();
                if(remove == 'E')
                {
                    remove = ll.remove();
                }

                ll.delete_node(remove);


                if(modified[i] == 'Y'){ll.Append_Node(make_pair(ref[i], make_pair(1,1)));}
                else{ll.Append_Node(make_pair(ref[i], make_pair(1,0)));}            
            }
        }
        else
        {
            if(modified[i] == 'Y'){ll.update(ref[i], 1, 1);}
            else{ll.update(ref[i], 1, 0);}            
        }
    }

    return 0;
}