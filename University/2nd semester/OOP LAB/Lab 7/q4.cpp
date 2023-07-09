#include <iostream>

class person
{
    int age;

protected:
    std ::string name;
    void set_a(int age)
    {
        this->age = age;
    }
    int get_a()
    {
        return age;
    }
};

class employee
{
    int emp_id;

protected:
    float salary;

public:
    void set_e(int emp_id)
    {
        this->emp_id = emp_id;
    }
    int get_e()
    {
        return emp_id;
    }
};

class manager : public person, public employee
{
    std ::string type;

protected:
    void set_type(std ::string type)
    {
        this->type = type;
    }
    void set_salary(float salary)
    {
        this->salary = salary;
    }
    void set_name(std ::string name)
    {
        this->name = name;
    }
    void setEmployeeID(int emp_id)
    {
        set_e(emp_id);
    }
    void setAge(int age)
    {
        set_a(age);
    }

    // getter functions
    std ::string get_type()
    {
        return type;
    }
    float get_salary()
    {
        return salary;
    }
    std ::string get_name()
    {
        return name;
    }
    int get_employeeID()
    {
        return (get_e());
    }
    int get_age()
    {
        return (get_a());
    }
};

class ITmanager : public manager
{
    int noOfPerson;

public:
    ITmanager(int age, std ::string name, int empID, float salary, std ::string type, int noOfPerson)
    {
        setAge(age);
        set_name(name);
        setEmployeeID(empID);
        this->noOfPerson = noOfPerson;
        set_type(type);
        set_salary(salary);
    }
    void Display();
};

void ITmanager ::Display()
{
    std ::cout << "\nAge: " << get_age()
               << "\nName: " << get_name()
               << "\nEmployee ID: " << get_employeeID()
               << "\nSalary: " << get_salary()
               << "\nType: " << get_type()
               << "\nNumber of persons: " << noOfPerson;
}

int main(void)
{
    ITmanager obj(18, "Sohaib Sarosh Shamsi", 3278, 75000, "Part-time", 103);
    obj.Display();
    return 0;
}