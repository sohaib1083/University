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
    int HashFunc(int k)
    {
        return (k % size);
    }
    void Insert(int k, int v)
    {
        int index = HashFunc(k);
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

        for (int i = 0; i < size; i++)
        {
            if (t[index % size] != NULL)
            {
                index++;
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
        int index = HashFunc(k);

        for (int i = 0; i < size; i++)
        {
            if (t[(index % size)]->k == k)
            {
                return index % size;
            }
            else
            {
                index++;
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
                cout << t[i]->k << "---> " << t[i]->v << endl;
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
    HMT.Insert(24, 1);
    HMT.Insert(52, 2);
    HMT.Insert(91, 3);
    HMT.Insert(67, 4);
    HMT.Insert(48, 5);
    HMT.Insert(89, 6);
    HMT.traverse();

    // seearching the key: 82
    cout <<"value found at index: " <<HMT.SearchKey(48);
    cout << endl
         << endl;
    // removing the value pair with the key 19     
    HMT.Remove(67);
    HMT.traverse();
    return 0;
}