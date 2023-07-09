#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class Employee
{
    char Employee_n[25];
    const int Employee_id_num;

    public:
        Employee ();

        Employee(char *employee, int id_num) : Employee_id_num(id_num)
        {
            strncpy(Employee_n, employee, 25);
        }

        void set_n(char *x)
        {
            strncpy(Employee_n, x, 25);
        }

        char *get_n()
        {
            return Employee_n;
        }

        int get_id_num()
        {
            return Employee_id_num;
        }
};

void input(char *n, int *id_num,  int num);
void output(Employee E, int num);

int main()
{
    char n[25];
    int id_num;
     
    input (n, &id_num, 1);
    Employee emp1(n, id_num);

    input (n, &id_num, 2);
    Employee emp2(n, id_num);

    input (n, &id_num, 3);
    Employee emp3(n, id_num);

    output (emp1, 1);
    output (emp2, 2);
    output (emp3, 3);

    return 0;
}

void input(char *n, int *id_num,  int num)
{
    cout << "name of employee #" << num << " : ";
    cin >> n;
    cout << "id of Employee #" << num << " : ";
    cin >> *id_num;
}

void output(Employee E, int num)
{
    cout << "\nThe name of the Employee #" << num << " is " << E.get_n() << ".\n";
    cout << "The id of Employee #" << num << " is " << E.get_id_num() << ".";
}