#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// max size of jagged array
#define TableSize 100

// To extract last 2 digits of a phone number
int Last_digit(string p)
{
    int size = p.size();
    stringstream ss;
    string l = p.substr(size - 4, 4);
    // conversion
    int num;
    ss << l;
    ss >> num;
    return num;
}

// contact node
class Contact
{
public:
    int key;
    string pn;
    string name;
    Contact *next;
    Contact() {}
    Contact(int k, string p, string n)
    {
        this->key = k; // key will store the hash value returned from hashing function
        this->name = n;
        this->pn = p;
        this->next = NULL;
    }

    void print_Contact()
    {
        cout << key << "  " << name << "   " << pn << endl;
    }
};

class Contact_Book
{
private:
    Contact **t;

public:
    Contact_Book()
    {
        // initialise every location with NULL
        t = new Contact *[TableSize];
        for (int i = 0; i < TableSize; i++)
            t[i] = NULL;
    }

    int HashFunc(int k)
    {
        return (k % TableSize);
    }

    void Insert(string p, string n)
    {
        int ld = Last_digit(p);
        int index = HashFunc(ld);
        Contact *newEntry = new Contact(index, p, n);

        if (t[index] == NULL)
        {
            t[index] = newEntry;
            // cout << "value added" << endl;
            return;
        }

        Contact *temp;

        // chaining
        temp = t[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEntry;
        return;
    }

    // gives O(1) unless chaining
    Contact *Search_via_phone_num(string n)
    {
        int ld = Last_digit(n);
        int index = HashFunc(ld);
        for (int i = 0; i < TableSize; i++)
        {
            if (t[index] == NULL)
            {
                cout<<"NO SUCH NUMBER FOUND";
                return NULL;
            }
            if (t[(index % TableSize)]->pn == n)
            {
                Contact *myNode = t[index];
                return myNode;
            }

            Contact *temp = t[index];

            // traverse LL to find the required node
            while (temp != NULL)
            {
                if (temp->pn == n)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }

        return NULL;
    }

    // O(n) since traversing through whole jagged array
    Contact *Search_via_name(string n)
    {
        for (int i = 0; i < TableSize; i++)
        {
            if (t[i] != NULL)
            {
                Contact *temp = t[i];
                while (temp != NULL)
                {
                    if (temp->name == n)
                    {
                        return temp;
                    }
                    temp = temp->next;
                }
            }
        }
        return NULL;
    }

    void remove_through_num(string num)
    {
        Contact *pos = Search_via_phone_num(num);
        int key_to_remove = pos->key;

        if (pos == NULL)
        {
            cout << "Value not found";
            return;
        }

        // first element in the jagged array
        if (t[key_to_remove]->pn == num)
        {
            // here's the problem
            t[key_to_remove] = t[key_to_remove]->next;
            pos->next = NULL;
            delete pos;
            return;
        }

        Contact *first = t[key_to_remove];
        Contact *second = t[key_to_remove]->next;

        // here is some problem
        while (second != NULL)
        {
            if (second->pn == num)
            {
                first->next = second->next;
                delete (second);
                second->next = NULL;
                return;
                // delete
            }
            first = second;
            second = second->next;
        }
    }

    void remove_through_name(string n)
    {
        Contact *pos = Search_via_name(n);
        int key_to_remove = pos->key;

        if (pos == NULL)
        {
            cout << "Value not found";
            return;
        }

        // first element in the jagged array
        if (t[key_to_remove]->name == n)
        {
            t[key_to_remove] = t[key_to_remove]->next;
            pos->next = NULL;
            delete pos;
            return;
        }

        Contact *first = t[key_to_remove];
        Contact *second = t[key_to_remove]->next;

        // here is some problem
        while (second != NULL)
        {
            if (second->name == n)
            {
                first->next = second->next;
                delete (second);
                second->next = NULL;
                return;
                // delete
            }
            first = second;
            second = second->next;
        }
    }

    void update_through_num(string pn)
    {
        Contact *myNode = Search_via_phone_num(pn);

        if (myNode == NULL)
        {
            cout << "VALUE NOT FOUND";
            return;
        }

        string name, num;
        // updation by new node
        cout << "ENTER THE DETAILS TO UPDATE";
        cout << "\nEnter the name: ";
        fflush(stdin);
        getline(cin, name);
        // cin >> name;
        cout << "Enter the number: ";
        cin >> num;
        Insert(num, name); // new node added

        remove_through_num(pn); // remove old node
    }

    void update_through_name(string n)
    {
        Contact *myNode = Search_via_name(n);

        if (myNode == NULL)
        {
            cout << "VALUE NOT FOUND";
            return;
        }

        string name, num;
        // updation by new node
        cout << "ENTER THE DETAILS TO UPDATE";
        cout << "\nEnter the name: ";
        fflush(stdin);
        getline(cin, name);
        // cin >> name;
        cout << "Enter the number: ";
        cin >> num;
        Insert(num, name); // new node added

        remove_through_name(n); // remove old node
    }

    void traverse()
    {
        cout << setw(3) << "K" << setw(15) << "Name" << setw(23) << "Number" << endl;
        for (int i = 0; i < TableSize; i++)
        {
            if (t[i] != NULL)
            {
                Contact *temp = t[i];
                while (temp != NULL)
                {
                    cout << setw(5) << temp->key << setw(15) << temp->name << setw(25) << temp->pn << endl;
                    temp = temp->next;
                }
            }
        }
    }

    ~Contact_Book()
    {
        delete[] t;
        t = NULL;
    }

    void rewritingdata()
    {
        fstream fout;
        fout.open("sample.txt");

        for (int i = 0; i < TableSize; i++)
        {
            if (t[i] != NULL)
            {
                Contact *temp = t[i];
                while (temp != NULL)
                {
                    fout << temp->name << endl
                         << temp->pn << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

main(void)
{
    Contact_Book c;
    string n, p;

    // reading from data file ,making nodes and then adding it to linked list
    fstream newfile;

    newfile.open("sample.txt", ios::in); // open a file to perform read operation using file object
    if (newfile.is_open())
    { // checking whether the file is open
        string fname, fnum;
        while (getline(newfile, fname))
        {                           // read data from file object and put it into string fname.
            getline(newfile, fnum); // read data from file object and put it into string fnum.
            // Contact *fc = new Contact(1, fname, fnum);
            c.Insert(fnum, fname);
        }
        newfile.close(); // close the file object.
    }
    int ch = 1, n1;

    while (ch != 6)
    {

        cout << "1.Add a contact \t  2.search contact  \t 3.delete a contact \t 4.Edit  \t 5.print " << endl;
        cout << "Enter your choice :";
        cin >> ch;
        system("cls");

        // do while starts
        switch (ch)
        {
            // choices options

        case 1:
        {
            fflush(stdin);
            cout << "ENTER NAME :" << endl;
            fflush(stdin);
            getline(cin, n);

            cout << "ENTER PHONENUMBER :" << endl;
            fflush(stdin);
            getline(cin, p);

            c.Insert(p, n);
            cout << "CONTACT ADDED TO NOTEBOOK" << endl;
        }
        break;

        case 2: // search a node
        {
            int choice1;
            cout << "1.Search through number \t  2.search through name" << endl;
            cin >> choice1;

            if (choice1 == 1)
            {
                string num;
                cout << "Enter the number of the contact you want to search: ";
                fflush(stdin);
                getline(cin, num);
                Contact *val = c.Search_via_phone_num(num);
                val->print_Contact();
            }
            else if (choice1 == 2)
            {
                string name;
                cout << "Enter the name of the contact you want to search: ";
                fflush(stdin);
                getline(cin, name);
                Contact *val = c.Search_via_name(name);
                if (val == NULL)
                {
                    cout << "NO SUCH RECORD EXIST";
                }
                else
                {
                    val->print_Contact();
                }
            }
        }
        break;
        case 3: // Delete a node
        {
            int choice1;
            cout << "1.Delete through number \t  2.Delete through name" << endl;
            cin >> choice1;

            if (choice1 == 1)
            {
                string num;
                cout << "Enter the number of the contact you want to delete: ";
                fflush(stdin);
                getline(cin, num);
                c.remove_through_num(num);
                cout << "CONTACT DELETED SUCCESSFULLY" << endl;
            }
            else if (choice1 == 2)
            {
                string name;
                cout << "Enter the name of the contact you want to delete: ";
                fflush(stdin);
                getline(cin, name);
                c.remove_through_name(name);
                cout << "CONTACT DELETED SUCCESSFULLY" << endl;
            }

            break;
        }
        case 4:
        { // EDIT A NODE
            int choice1;
            cout << "1.Edit through number \t  2.Edit through name" << endl;
            cin >> choice1;

            if (choice1 == 1)
            {
                string num;
                cout << "Enter number of the contact you want to Edit: ";
                fflush(stdin);
                getline(cin, num);
                c.update_through_num(num);
                cout << "CONTACT UPDATED SUCCESSFULLY" << endl;
            }
            else if (choice1 == 2)
            {
                string name;
                cout << "Enter name of the contact you want to Edit: ";
                fflush(stdin);
                getline(cin, name);
                c.update_through_name(name);
                cout << "CONTACT UPDATED SUCCESSFULLY" << endl;
            }

            break;
        }
        case 5:
        { // PRINT CONTACTS
            c.traverse();
            break;
        }

            // switch closing brackets
        }
        cout << "\n\n\tPress 1.To continue press 2.To exit ";
        cin >> n1;
        if (n1 == 2)
            break;
        system("cls");
    }

    c.rewritingdata();
}