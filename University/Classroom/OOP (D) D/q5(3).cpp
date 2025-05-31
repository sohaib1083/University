#include <iostream> 

using namespace std;

float info (float rate, float mins, float income); // proto-type
int main (void)
{
    float rate, mins, income;

    cout<< "Enter hourly rate : "<< endl;
    cin>> rate;

    cout<< "Enter total consulting time in minutes : "<< endl;
    cin>> mins;

    cout<< "Enter income : "<< endl;
    cin>> income;

    float bill_amount = info(rate, mins, income);

    cout<< endl<< endl;
    cout<< "The bill amount is : "<< bill_amount<< endl;


}

float info (float rate, float mins, float income)
{
    float bill;

    if (income <= 25000) // a
    {
        if (mins <= 30)
        {
            bill = 0;
        }
        else if (mins > 30)
        {
            bill = (rate * 0.40 * ((mins - 30)/60));
        }
    }
    else if (income > 25000) // b
    {
        if (mins <= 20)
        {
            bill = 0;
        }
        else if (mins > 20)
        {
            bill = (rate * 0.70 * ((mins - 20)/60));
        }

    }

    return bill;
}
