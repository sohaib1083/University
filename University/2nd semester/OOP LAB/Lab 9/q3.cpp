#include <iostream>
using namespace std;

class account
{
protected:
    float balance = 0;

public:
    account(double a)
    {
        balance = a;
    }
    account()
    {
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }
    void withdrawal(double amount)
    {
        if (amount > balance)
        {
            cout << "Amount exceeds your current balance.";
        }
        else
        {
            balance -= amount;
        }
    }
    void checkBalance()
    {
        cout << "Your balance is : " << balance << '.';
    }
};

class interestAccount : public virtual account
{
protected:
    float interest;

public:
    interestAccount(double a) : account(a)
    {
    }
    void deposit(double amount)
    {
        interest = 0.30 * amount;
        amount += interest;
        account ::deposit(amount);
    }
};

class ChargingAccount : public virtual account
{
protected:
    const float fee = 3;

public:
    ChargingAccount(double a) : account(a)
    {
    }
    void withdrawal(double amount)
    {
        amount += fee;
        account ::withdrawal(amount);
    }
};

class ACI : public ChargingAccount, public interestAccount
{

    void transfer(double amount, account obj1)
    {
        obj1.withdrawal(amount);
    }
    void transfer(double amount, interestAccount obj2)
    {
        obj2.withdrawal(amount);
    }
    void transfer(double amount, ChargingAccount obj3)
    {
        obj3.withdrawal(amount);
    }

public:
    ACI(double amount) : ChargingAccount(amount), interestAccount(amount)
    {
    }
};

int main(void)
{
    ACI o1(10);
    ACI *p;

    o1.checkBalance();
    o1.deposit(100);
    o1.checkBalance();
    o1.withdrawal(50);
    o1.checkBalance();
    return 0;
}