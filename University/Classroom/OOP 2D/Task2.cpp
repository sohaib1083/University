#include <iostream>

using namespace std;

class account{
    int balance;

    public:

    int initialise(int a)
    {
        if (a < 0)
        {
            cout<< "The initial balance was invalid"<< endl;
            balance = 0;
            return -1;
        }
        else 
        {
            balance = a;
        }
    }

    void credit (int b)
    {
        balance += b;
    }

    int debit (int c)
    {
        if (c > balance)
        {
            cout<< "debit amount exceeded the account balance"<< endl;
            return -1;
        }
        else 
        {
            balance -= c;
        }
    }

    int getBalance(void)
    {
        return balance;
    }
};

int main (void)
{
    account test1;

    test1.initialise(10);
    test1.credit(30);
    test1.debit(20);
    cout<< test1.getBalance()<< endl; //20

    account test2;

    test2.initialise(100);
    test2.credit(100);
    test2.debit(201); // error : debit amount exceeded the account balance
    cout<< test2.getBalance()<< endl; // 200

}