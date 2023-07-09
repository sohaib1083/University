#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(){
            next = NULL;
        }
        Node(char data){
            this->data = data;
        }
};
class Queue{
    private:
        Node* nodes,*front,*rear;
        int limit,current;
    public:
        Queue(int l){
            nodes = NULL;
            front = NULL;
            rear = NULL;
            limit = l;
            current = 0;
        }
        bool queueCapacity(){
            if(current == limit)
                return true;
            return false;
        }
        void addMember(int data){
            if(queueCapacity()){
                cout<<"Queue is already full."<<endl;
            }
            else
            {
                Node * temp = new Node(data);
                current++;
                if(front == NULL && rear == NULL){
                    front = temp;
                    rear = temp;
                }
                else
                {
                    rear->next = temp;
                    rear = temp;
                }  
            }
        }
        void removeMember(){
            if(front == NULL && rear == NULL){
                cout<<"Queue is empty. "<<endl;
            }
            else
            {
                current--;
                if(front == rear)
                {
                    delete front;
                    front = NULL;
                    rear = NULL;
                }
                else
                {
                    Node* temp = front;
                    front = front ->next;
                    delete temp;
                }
            }
        }
        void traverse(){
            Node* temp = front;
            while(temp!=rear){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<< temp->data;
            cout<<endl;
        }
};
int main(){
    Queue q(15);
    q.addMember('P');
    q.addMember('Q');
    q.addMember('E');
    q.traverse();
    q.removeMember();
    q.traverse();
}