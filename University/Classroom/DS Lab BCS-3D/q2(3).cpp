#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* link;
};
 
struct Node* top;
 
// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{
     
    // Create new node temp and allocate memory
    struct Node* temp;
    temp = new Node();
 
    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
 
    // Initialize data into temp data field
    temp->data = data;
 
    // Put top pointer reference into temp link
    temp->link = top;
 
    // Make temp as top of Stack
    top = temp;
}

void print_rev (Node * temp)
{
    
    if (temp == NULL)
        return;
        
    print_rev(temp->link);
    cout<<temp->data<<" ";    
}

void display()
{
    cout<< "forward direction: "<< endl;
    struct Node * temp = top;

    while (temp != NULL)
    {
        cout<< temp->data<< " ";
        temp = temp->link;
    }

    cout<< endl<< "reverse order: "<< endl;
    Node * t = top;
    print_rev(t);
}

void pop()
{
    Node * temp = top;
    top = top->link;
    delete(temp);
}



int main (void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    cout<< endl<< endl;
    pop();
    pop();
    display();
    return 0;
}