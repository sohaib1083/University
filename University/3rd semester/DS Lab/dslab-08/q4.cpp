#include <iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int front,rear;
    public:
        Queue(int s){
            front = 0;
            rear = -1;
            size = s;
            arr = new int[s];
        }
        bool queueCapacity(){
            if(rear == size-1){
                return true;
            }
            return false;
        }
        void addMember(int data){
            if(queueCapacity()){
                cout<<"Queue is already full."<<endl;
            }
            else{
                arr[++rear] = data;
            }
        }
        void removeMember(){
            if(rear == 0){
                cout<<"Queue is empty."<<endl;
            }
            else if(rear == front){
                front = 0;
                rear = 0;
            }
            else{
                arr[front++] = 0;
            }
        }

    void print()
    {
        int i;
        for (i = front; i<rear; i++)
        {
            cout<< arr[i]<< " ";
        }
        cout<< arr[i];
    }
};


int main (void)
{
    Queue q(5);
    q.addMember(2);
    
    q.addMember(4);
    
    q.addMember(6);

    q.print();
    cout<< endl;

    q.removeMember();

    q.print();
    return 0;
}
