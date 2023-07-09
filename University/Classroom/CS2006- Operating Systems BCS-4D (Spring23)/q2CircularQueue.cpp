#include <bits/stdc++.h>
using namespace std;

#define SIZE 3 // Frame Size

class Circular_Queue
{
public:
    pair<char, pair<int, int>> arr[SIZE];
    int front, rear;

    Circular_Queue()
    {
        front = rear = -1;
    }

    void print_queue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
            cout << "(" << arr[i].first << "," << arr[i].second.first << "," << arr[i].second.second << "), ";
        cout << "(" << arr[i].first << "," << arr[i].second.first << "," << arr[i].second.second << ")" << endl;
    }

    int size_queue()
    {
        if (front != -1)
        {
            return (rear - front + 1);
        }
        return 0;
    }

    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    void Push(pair<char, pair<int, int>> element)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = element;
        }
    }

    char deQueue()
    {
        pair<char, pair<int, int>> element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            element = arr[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            return (element.first);
        }
    }

    int remove()
    {
        for (int i = front; i <= rear; i++)
        {
            if (arr[i].second.first == 0 && arr[i].second.second == 0)
            {
                return i;
            }
        }
        for (int i = front; i <= rear; i++)
        {
            if (arr[i].second.first == 0 && arr[i].second.second == 1)
            {
                return i;
            }
        }
        for (int i = front; i <= rear; i++)
        {
            if (arr[i].second.first > 0)
            {
                arr[i].second.first--;
            }
        }
        return -1;
    }

    void insert(int index, pair<char, pair<int, int>> element)
    {
        arr[index] = element;
    }

    int search(char element)
    {
        for (int i = front; i <= rear; i++)
        {
            if (arr[i].first == element)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string ref = "01362452502312524";
    string modified = "YNNNNYNNYNNNYNYNN";

    Circular_Queue q;

    for (int i = 0; i < ref.size(); i++)
    {
        // q.print_queue();
        int index = q.search(ref[i]);
        if (index == -1)
        {
            if (q.size_queue() < SIZE)
            {
                if (modified[i] == 'Y')
                {
                    q.Push(make_pair(ref[i], make_pair(1, 1)));
                }
                else
                {
                    q.Push(make_pair(ref[i], make_pair(1, 0)));
                }

                cout << "Element " << ref[i] << " Pushed with thy status (" << 1 << "," << 0 << ")\n";
            }
            else
            {
                int check = q.remove();
                if (check == -1)
                {
                    check = q.remove();
                }

                cout << "Element " << q.arr[check].first << " Removed with the status (" << q.arr[check].second.first << ","
                     << q.arr[check].second.second << ")\n";

                if (modified[i] == 'Y')
                {
                    q.insert(check, make_pair(ref[i], make_pair(1, 1)));
                    cout << "Element " << ref[i] << " Pushed with the status (" << 1 << "," << 1 << ")\n";
                }
                else
                {
                    q.insert(check, make_pair(ref[i], make_pair(1, 0)));
                    cout << "Element " << ref[i] << " Pushed with the status (" << 1 << "," << 0 << ")\n";
                }
            }
        }
        else
        {
            if (modified[i] == 'Y')
            {
                q.insert(index, make_pair(ref[i], make_pair(1, 1)));
            }
            else
            {
                q.insert(index, make_pair(ref[i], make_pair(1, 0)));
            }

            cout << "Element " << q.arr[index].first << " Status updated to (" << q.arr[index].second.first << ","
                 << q.arr[index].second.second << ")\n";
        }
        cout << endl;
    }

    return 0;
}