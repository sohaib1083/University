#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
    string name, accountNum, type;
    float balance;
    static float rateOfInterest;

public:
    bankAccount(void)
    {
        name = "Default";
        accountNum = "ABC123";
        type = "Savings";
        balance = 0.0;
    }
    bankAccount(string n, string a, string t, float balance)
    {
        name = n;
        accountNum = a;
        type = t;
        this->balance = balance;
    }

    static void DisplayRateOfInterest(void)
    {
        cout << endl
             << "The rate of interest is : " << rateOfInterest;
    }
    void displayInfo(void)
    {
        cout << endl
             << endl
             << "The name is : " << name << endl
             << "The account number is : " << accountNum << endl
             << "The type of account is : " << type << endl
             << "The balance is : " << balance;
    }
    void withdraw(void)
    {
        char choice;
        float amount = 0;
        CheckBalance();
        cout << endl
             << "Do you still want to withdraw money (Y/N) ?";
        cin >> choice;

        if (choice == 'Y')
        {
            cout
                << "Enter amount to withdraw: ";
            cin >> amount;
        }
        balance = balance - amount;
        cout
            << amount << " deducted from your account";
    }
    void CheckBalance(void)
    {
        cout
            << "The balance is : " << balance;
    }
    void Deposit(float dep)
    {
        balance = balance + dep;
    }
    static void setROI(float);
};

float bankAccount ::rateOfInterest{0};
void bankAccount ::setROI(float rate) { rateOfInterest = rate; }

int main(void)
{
    float rate;
    cout << "Enter the fixed rate of interest";
    cin >> rate;
    bankAccount ::setROI(rate);

    float dep;

    // for default constructor
    bankAccount obj1;
    cout << endl
         << "Enter amount to deposit: ";
    cin >> dep;

    obj1.Deposit(dep);
    obj1.withdraw();
    obj1.displayInfo();
    obj1.DisplayRateOfInterest();

    cout << endl
         << endl;

    // for parameterized constructor
    string name, acc, t;
    float b;
    cout << endl
         << "Enter name :";
    cin >> name;
    cout << endl
         << "Enter account number : ";
    cin >> acc;
    cout << endl
         << "Enter type : ";
    cin >> t;
    cout << endl
         << "Enter balance : ";
    cin >> b;

    bankAccount obj2(name, acc, t, b);

    cout << endl
         << "Enter amount to deposit: ";
    cin >> dep;

    obj2.Deposit(dep);
    obj2.withdraw();
    obj2.displayInfo();
    obj2.DisplayRateOfInterest();
    return 0;
}