#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class employee{
    string f_name;
    string l_name;
    int salary;

    public:
    void setf(string a){
        f_name = a;
    }
    void setl(string b){
        l_name = b;
    }
    void sets (int c){
        if (c >= 0){
            salary = c;
        }
        else{
            salary = 0;
        }
    }

    string get_fname(void)
    {
        return f_name;
    }

    string get_lname (void)
    {
        return l_name;
    }

    int get_salary (void)
    {
        return salary;
    }
};
int main (void)
{
    string f_name;
    string l_name;
    int sal;

    employee obj1[2];

for (int i=0; i<2; i++)
{
    cout<<"\nEmployee number "<< i+1;
    cout<< "\nEnter first name:";
    fflush(stdin);
    cin>> f_name;
    fflush(stdin);
    obj1[i].setf(f_name);

    cout<< "Enter last name:";
    fflush(stdin);
    getline (cin, l_name);
    fflush(stdin);
    obj1[i].setl(l_name);

    cout<< "Enter salary:";
    cin>> sal;
    obj1[i].sets(sal);
}    

    cout<< fixed << setprecision(2);

// incrementing and displaying new salary
for (int i=0; i<2; i++)
{
    cout<< "\nThe yearly salary for employee "<< i+1 << " is : "<< setw(8) <<obj1[i].get_salary() * 12;
    cout<< "\nThe new yearly salary for employee "<< i+1 << " is : "<< setw(6) << obj1[i].get_salary() * 12.0 * 1.1<< endl;
}

    return 0;
}