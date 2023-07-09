#include <iostream>
#include <string>
using namespace std;

class RentCalculator
{
    const float rentPerDay = 1000.95;
    const string customerName;
    int numberOfDays;
    float customerRent;

public:
    RentCalculator(string name, int days) : customerName{name}
    {
        numberOfDays = days;
    }

    void RentWithBonus()
    {
        customerRent = numberOfDays * rentPerDay;
        customerRent = customerRent - rentPerDay;
    }

    void RentWithoutBonus()
    {
        customerRent = numberOfDays * rentPerDay;
    }

    void DisplayRent()
    {
        cout << "\nName of customer: " << customerName;
        cout << "\nNumber of days of stay: " << numberOfDays;
        cout << "\nRent charged: " << customerRent;
    }
};

int main()
{
    string name[2];
    int i, days[2];

    for (i = 0; i < 2; i++)
    {
        cout << "Enter Customer " << i + 1 << " name: ";
        cin >> name[i];
        cout << "Enter days: ";
        cin >> days[i];

        RentCalculator obj1(name[i], days[i]);
        system("cls");
        if (days[0] > 7)
        {
        obj1.RentWithBonus();   
        }
        else
        {
            obj1.RentWithoutBonus();
        }

        obj1.DisplayRent();
        cout<< endl;
    }

    // RentCalculator obj1(name[0], days[0]);
    // RentCalculator obj2(name[1], days[1]);

    // if (days[0] > 7)
    // {
    //     obj1.RentWithBonus();
    // }
    // else
    // {
    //     obj1.RentWithoutBonus();
    // }

    // if (days[1] > 7)
    // {
    //     obj2.RentWithBonus();
    // }
    // else
    // {
    //     obj2.RentWithoutBonus();
    // }

    // obj1.DisplayRent();
    // obj2.DisplayRent();

    return 0;
}