#include <iostream>
using namespace std;
#define size 10

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashMapTable
{
private:
    HashNode **t;

public:
    HashMapTable()
    {
        t = new HashNode *[size];
        for (int i = 0; i < size; i++)
            t[i] = NULL;
    }

    int HashFunc(int k)
    {
        return (k % size);
    }
    void Insert(int k, int v)
    {
        int index = HashFunc(k);
        HashNode *newEntry = new HashNode(k, v);

        if (t[index] == NULL)
        {
            t[index] = newEntry;
            cout << "value added" << endl;
            return;
        }

        HashNode *temp;
        temp = t[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEntry;
        return;
    }
    int SearchKey(int k)
    {
        int index = HashFunc(k);
        for (int i = 0; i < size; i++)
        {
            if (t[index]->key == k)
                return index;

            HashNode *temp = t[index];

            while (temp != NULL)
            {
                if (temp->key == k)
                {
                    return index;
                }
                temp = temp->next;
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

        
        if (t[pos]->key == k)
        {
            t[pos]= t[pos]->next;
            return;
        }

        HashNode *first = t[pos];
        HashNode *second = t[pos]->next;
        
        while (second != NULL)
        {
            if (second->key == k)
            {
                first->next = second->next;
                delete (second);
                second = NULL;
                return;
                // delete
            }
            first = second;
            second = second->next;
        }
    }

    void traverse()
    {
        cout << "K      V" << endl;
        for (int i = 0; i < size; i++)
        {
            if (t[i] != NULL)
            {
                HashNode *temp = t[i];
                while (temp != NULL)
                {
                    cout << temp->key << "--->" << temp->value << endl;
                    temp = temp->next;
                }
            }
        }
    }

    ~HashMapTable()
    {
        delete[] t;
        t = NULL;
    }
};

main(void)
{
    HashMapTable HMT;

    // values given in question
    HMT.Insert(42, 1);
    HMT.Insert(19, 2);
    HMT.Insert(10, 3);
    HMT.Insert(2, 4);
    HMT.traverse();

// seearching the key: 82
    cout <<"value found at index: " <<HMT.SearchKey(2);
    cout << endl
         << endl;
    // removing the value pair with the key 19     
    HMT.Remove(2);
    HMT.traverse();
    return 0;
}