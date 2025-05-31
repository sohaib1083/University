#include <iostream>
using namespace std;

class person{
    public:
    virtual void getData()
    {
        cout<< "get data of person"<< endl;
    }
    virtual void displayData()
    {
        cout<< "display data of person"<< endl;
    }
    virtual void bonus()
    {
        cout<< "bonus data of person"<< endl;
    }
};

class admin : public virtual person{
    public:
    void getData()
    {
        cout<< "get data of admin"<< endl;
    }
    void displayData()
    {
        cout<< "display data of admin"<< endl;
    }
    void bonus()
    {
        cout<< "bonus data of admin"<< endl;
    }
};

class account : public virtual person{
    public:
    void getData()
    {
        cout<< "get data of acc"<< endl;
    }
    void displayData()
    {
        cout<< "display data of acc"<< endl;
    }
    void bonus()
    {
        cout<< "bonus data of acc"<< endl;
    }
};


class master : public admin,  account{
    public:
    void getData()
    {
        cout<< "get data of master"<< endl;
    }
    void displayData()
    {
        cout<< "display data of master"<< endl;
    }
    void bonus()
    {
        cout<< "bonus data of master"<< endl;
    }

    
};


int main()
{
    person * ptr;
    master obj1;
    admin obj2;
    account obj3;

    ptr = &obj1;
    ptr ->bonus();
    ptr->displayData();
    ptr->getData();

    cout<< endl;

    ptr = &obj2;
    ptr ->bonus();
    ptr->displayData();
    ptr->getData();

    cout<< endl;

    ptr = &obj3;
    ptr ->bonus();
    ptr->displayData();
    ptr->getData();
    return 0;
}