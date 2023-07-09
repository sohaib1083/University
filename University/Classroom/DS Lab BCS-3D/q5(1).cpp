#include <iostream>
using namespace std;

void BuildHeap (int arr[], int N);
void Heapify(int arr[], int s, int i);

class Priorty_queue
{
public:
    int size;
    int arr[100];
    Priorty_queue()
    {
        size = 0;
        //arr[100] = {0};
    }
    void push(int val)
    {
        
        int index = size;
        arr[index] = val;
        size++;
        BuildHeap(arr, size);
    }

    void pop()
    {
            int lastElement = size;
            arr[0] = arr[lastElement];
            size--;
            Heapify(arr, size, 0);
    }

    int top ()
    {
        return arr[0];
    }

    int size_of_queue ()
    {
        return size;
    }

    bool isEmpty ()
    {
        if (size == 0)
            return true;

        return false;    
    }

    void print ()
    {
        for (int i=0; i<size; i++)
        {
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }
};


void BuildHeap (int arr[], int N)
{
    for (int i=N/2 -1; i>=0; i--){
        Heapify(arr, N, i);
    }
}


void Heapify(int arr[], int s, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < s && arr[l] > arr[largest])
        largest = l;

    if (r < s && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, s, largest);
    }
}

int main(void)
{
    Priorty_queue q1;
    q1.push(4);
    q1.push(1);
    q1.push(3);
    q1.push(9);
    q1.push(7);
    q1.print();

    q1.pop();
    q1.pop();
    q1.print();

    cout<<q1.isEmpty()<<" ";
    cout<<q1.size_of_queue()<< " ";
    cout<<q1.top();
    return 0;
}