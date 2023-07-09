#include <iostream>
using namespace std;
#define size 10

class HashTableEntry
{
public:
    int k;
    int v;
    HashTableEntry(int k, int v)
    {
        this->k = k;
        this->v = v;
    }
    HashTableEntry() {}
};
class HashMapTable
{
private:
    HashTableEntry **t;
    int count;

public:
    HashMapTable()
    {
        count = 0;
        t = new HashTableEntry *[size];
        for (int i = 0; i < size; i++)
        {
            t[i] = NULL;
        }
    }
    int Hash1(int k)
    {
        return (k % size);
    }

    int Hash2(int k)
    {
        int a = 7 - (k % 7);
        return a;
    }
    void Insert(int k, int v)
    {
        int index = Hash1(k);
        HashTableEntry *newEntry = new HashTableEntry(k, v);

        if (count >= 10)
        {
            cout << "Hash table is already full";
            return;
        }

        count++;
        if (t[index] == NULL)
        {
            t[index] = newEntry;
            cout<< "value added"<< endl;
            return;
        }

        for (int i = 1; i < size; i++)
        {
            if (t[index % size] != NULL)
            {
                index= (Hash1(k) + i*Hash2(k))%size;
                continue;
            }
            else
            {
                t[index % size] = newEntry;
                return;
            }
        }
    }
    int SearchKey(int k)
    {
        int index = Hash1(k);

        for (int i = 1; i < size; i++)
        {
            if (t[(index % size)]->k == k)
            {
                return index % size;
            }
            else
            {
                index= (Hash1(k) + i*Hash2(k))%size;
            }
        }

        return -1;
    }
    void Remove(int k)
    {
        int pos = SearchKey(k);

        if (pos == -1)
        {
            cout << "Value not found";
            return;
        }

        count--;
        delete t[pos];
        t[pos] = NULL;
    }

    void traverse()
    {
        cout << "K      V" << endl;
        for (int i = 0; i < size; i++)
        {
            if (t[i] != NULL)
            {
                cout << t[i]->k << "--->" << t[i]->v << endl;
            }
        }
    }

    ~HashMapTable()
    {
        delete[] t;
        t = NULL;
    }
};

int main(void)
{
    HashMapTable HMT;
    HMT.Insert(20, 1);
    HMT.Insert(34, 2);
    HMT.Insert(45, 3);
    HMT.Insert(70, 4);
    HMT.Insert(56, 5);
    HMT.traverse();

// seearching the key: 82
    cout <<"value found at index: " <<HMT.SearchKey(70);
    cout << endl
         << endl;
    // removing the value pair with the key 19     
    HMT.Remove(70);
    HMT.traverse();
    return 0;
}