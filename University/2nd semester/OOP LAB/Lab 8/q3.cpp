#include <iostream>
using namespace std;

class person{
    protected:
    string emp_id;
    public:
    virtual void getData(string emp_id, float income = 0 ,string name ="x")
    {
        this -> emp_id = emp_id;
    }
    virtual void displayData()
    {
        cout<< "Employee id is : "<< emp_id<< endl;
        
    }
};

class admin : public person{
    string name;
    float monthly_income;
    
    public:
    void getData(string name, float monthly_income, string emp_id)
    {
    	person :: getData(emp_id);
        this -> name = name;
        this -> monthly_income = monthly_income;
    }

    void displayData()
    {
        cout<< "The name is: "<< name<< endl<< "The monthly income: "<< monthly_income<< endl;
        person :: displayData();
    }

    void bonus (void)
    {
        cout<< "The bonus awarded is: "<< monthly_income*0.05<< endl; // problem in maths
    }
};


class accounts : public person{
    string name;
    float monthly_income;
    
    public:
    void getData(string name, float monthly_income, string emp_id)
    {
    	person :: getData(emp_id);
        this -> name = name;
        this -> monthly_income = monthly_income;
    }

    void displayData()
    {
        cout<< "The name is: "<< name<< endl<< "The monthly income: "<< monthly_income<< endl;
        person :: displayData();
    }

    void bonus (void)
    {
        cout<< "The bonus awarded is: "<< monthly_income*0.05<< endl; // problem in maths
    }
};

int main (void)
{
	person * ptr;
	accounts obj1;
	ptr = &obj1;
	ptr->getData("Sohaib", 456.44, "21k-3278");
	ptr->displayData();
	obj1.bonus();
	
	person * ptr1;		
	admin obj2;
	ptr1 = &obj2;
	ptr1->getData("Abdullah", 44000, "21k-3240");
	ptr1->displayData();
	obj2.bonus();
	return 0;
}