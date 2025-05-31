#include <iostream>

using namespace std;

// proto-type
float res_billing(int &x);
float bus_billing(int &x, int &con);

int main (void)
{
    char customer_code;
    int acc, p_channels, connections;
    float bill_amount;


    cout<< "Enter account number :\n";
    cin >> acc;

    cout<< "Enter customer code :\n";
    cin >> customer_code;

    cout<< "Enter number of premium channels: \n";
    cin >>p_channels;

    if (customer_code == 'R' || customer_code == 'r')
    {
        bill_amount = res_billing(p_channels);
    }
    else if (customer_code == 'B' || customer_code == 'b')
    {
        cout<< "Enter number of basic connections: ";
        cin >> connections;

        bill_amount = bus_billing(p_channels, connections);
    }
    else
    {
        cout << "Wrong choice....";
    }

    cout << "The customer holding account number : "<< acc << " has the bill :"<< bill_amount;



}

float res_billing(int &x)
{
    float bill = 4.50 + 20.50 + (7.50 * x);
    return bill;
}

float bus_billing(int &x, int &con)
{
    float bill = 15;

    if (con > 10)
    {
        bill = bill + 75 + (con - 10)* 5.0;
    }
    else if (con > 0 && con <= 10)
    {
        bill = bill + 75;
    }
    else
    {
        cout<<"Wrong choice...";
    }

    bill = bill + (50.0 * x);
    return bill;
}