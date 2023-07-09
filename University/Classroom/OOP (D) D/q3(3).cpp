#include <iostream>
#include <string>

using namespace std;

class employee{
    string f_name;
    string l_name;
    double salary;

    public:
    void setf(string f)
    {
        f_name = f;  
    }
    void setl (string l)
    {
        l_name = l;
    }
    void sets (double s)
    {
        salary = s;
        if (salary < 0)
           salary = 0.0;
    }

    string get_fname(void)
    {
        return f_name;
    }

    string get_lname (void)
    {
        return l_name;
    }

    double get_salary (void)
    {
        return salary;
    }
};

int main (void)
{
    string f_name, l_name;
    double salary;

    // test application
    employee test;

    cout<< "\nEnter first name:";
    fflush(stdin);
    getline (cin, f_name);
    test.setf(f_name);

    cout<< "\nEnter last name:";
    fflush(stdin);
    getline (cin, l_name);
    test.setl(l_name);

    cout<< "\nEnter salary:";
    cin >> salary;
    test.sets(salary);

    cout<< "\nTest application: \nfirst name: "<< test.get_fname()<< "\nlast name: "<< test.get_lname()<< "\nsalary: "<< test.get_salary();

    cout<< "\n*************** employee 1 **************\n";
    // Employee 1
    employee person1;

    cout<< "\nEnter first name:";
    fflush(stdin);
    getline (cin, f_name);
    person1.setf(f_name);

    cout<< "\nEnter last name:";
    fflush(stdin);
    getline (cin, l_name);
    person1.setl(l_name);

    cout<< "\nEnter salary:";
    cin >> salary;
    person1.sets(salary);

    cout<< "\nperson1 application: \nfirst name: "<< person1.get_fname()<< "\nlast name: "<< person1.get_lname()<< "\nsalary: "<< person1.get_salary();
    salary = person1.get_salary();
    salary += salary * 0.10;
    person1.sets(salary); 
    cout<< "\n**********After salary increment:************\n";
    cout<< "salary: "<< person1.get_salary()<< endl<< endl;

   // Employee 2
    employee person2;

    cout<< "\n********************* employee 2 ********************\n";

    cout<< "\nEnter first name:";
    fflush(stdin);
    getline (cin, f_name);
    person2.setf(f_name);

    cout<< "\nEnter last name:";
    fflush(stdin);
    getline (cin, l_name);
    person2.setl(l_name);

    cout<< "\nEnter salary:";
    cin >> salary;
    person2.sets(salary);

    cout<< "\nperson2 application: \nfirst name: "<< person2.get_fname()<< "\nlast name: "<< person2.get_lname()<< "\nsalary: "<< person2.get_salary();
    salary = person2.get_salary();
    salary += salary * 0.10;
    person2.sets(salary); 
    cout<< "\n*************After salary increment:************\n";
    cout<< "salary: "<< person2.get_salary()<< endl<< endl;    

    return 0;
}

