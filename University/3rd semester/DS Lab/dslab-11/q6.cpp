#include <iostream>
using namespace std;
#define size 100
class pq
{
private:
    int front;
    int back;
    int data;
    int *arr;
    static int count;

public:
    pq()
    {
        this->back = -1;
        this->front = -1;
        arr = new int[size];
    }
    void Enqeue(int data)
    {
        if (isEmpty())
        {
            arr[++front] = data;
            back++;
        }
        else
        {
            if (data > arr[back])
            {
                count++;
                while (data > arr[back])
                    data--;
            }
            arr[++back] = data;
        }
    }
    void Print()
    {
        for (int i = 0; i <= back; i++)
        {
            cout << arr[i];
        }
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    int getCount()
    {
        return count;
    }
};
int pq::count = 0;

int main()
{
    pq O1;
    int n=4;
    int num;
    cout<<"Enter elements:\n";
    for (int i=0; i<n; i++)
    {
        cin>>num;
        O1.Enqeue(num);
    }

    cout <<"Number of steps: "<< O1.getCount();
}