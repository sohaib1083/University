#include <iostream>
using namespace std;

class person{
    protected:
    string name;
    public:
    virtual void getData() = 0;
    virtual bool isOutstanding() = 0;
    void getName()
    {
      cout<<"Enter name: ";
      cin>> name;  
    }
    void putName()
    {
        cout<< "Person's name is: "<< name;
    }
};

class student : public person{
    float gpa;
    void getData()
    {
        cout<< "Enter GPA: ";
        cin>> gpa;
    }
    bool isOutstanding()
    {
        if (gpa >= 3.5)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

class professor : public person{
    int publications;
    void getData()
    {
        cout<< "Enter number of publications:";
        cin>> publications;
    }
    bool isOutstanding()
    {
        if (publications> 100)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main (void)
{
    char choice, d_choice;
    do{
        cout<< "Do you want to insert data in professor or student? (P/S)";
        cin>> d_choice;

        if ((d_choice == 'p') || (d_choice = 'P'))
        {
            person * ptr = new professor;
            ptr->getName();
            ptr->getData();
            ptr->isOutstanding();
        }
        else if ((d_choice == 's') || (d_choice = 'S'))
        {
            person * ptr1 = new student;
            ptr1->getName();
            ptr1->getData();
            ptr1->isOutstanding();
        }
        cout<< "Do you want to add more data? (Y/N)";
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');
    return 0;
}