#include <iostream>
#include <string>
#include <cstring>

// class employee
class employee
{
    int empNo;
    char name[20];
    char des[20];

public:
    void getEmployeeDetails();
    void employee_display();
};

void employee ::getEmployeeDetails()
{
    std ::cout << "\nEnter employee number :";
    std ::cin >> empNo;
    std ::cout << "\nEnter name:";
    std ::cin >> name;
    std ::cout << "\nEnter decription:";
    std ::cin >> des;
};

void employee ::employee_display()
{
    std ::cout << "\nThe employee number is: " << empNo
               << "\nThe employee name is: " << name
               << "\nThe employee description is: " << des;
}

// class salary
class salary : private employee
{
    float bp, hra, da, pf, net_pay;

public:
    void getPayDetails()
    {
        getEmployeeDetails();
        std ::cout << "\nEnter basic pay: ";
        std ::cin >> bp;
        std ::cout << "\nEnter human resource allowance: ";
        std ::cin >> hra;
        std ::cout << "\nEnter dearness allowance: ";
        std ::cin >> da;
        std ::cout << "\nEnter profitability fund: ";
        std ::cin >> pf;
        Calculate_net_pay();
    }

    void Calculate_net_pay()
    {
        net_pay = bp + hra + da - pf;
    }

    void salary_display()
    {
        employee_display();
        std ::cout << "\nbasic pay: " << bp
                   << "\nhuman resources allowance: " << hra
                   << "\ndearness allowance: " << da
                   << "\nprofitability fund: " << pf
                   << "\nnet pay: " << net_pay;
    }
};

class BankCredit : private salary
{
    int accNo;
    char bankname[20];
    char IFSC[20];

    public:
    void getBankDetails()
    {
        getPayDetails();
        std ::cout << "\nEnter account number: ";
        std ::cin >> accNo;
        std ::cout << "\nEnter bank name: ";
        std ::cin >> bankname;
        std ::cout << "\nEnter IFSC: ";
        std ::cin >> IFSC;
    }

    void display(void)
    {
        salary_display();
        std ::cout << "\naccount number: " << accNo
                   << "\nbankname: " << bankname
                   << "\nIFSC: " << IFSC;
    }
};

int main(void)
{
    int n;
    std :: cout<< "Enter 'n' number of persons: ";
    std :: cin>> n;

    BankCredit * ptr = new BankCredit[n];


    for (int i = 0; i < n; i++)
    {
        (ptr + i)-> getBankDetails();
    }
    // dispalying data
    for (int i = 0; i < n; i++)
    {
        std :: cout<< "\nperson #"<< i+1<< std :: endl;
        (ptr + i)-> display();
    }
}