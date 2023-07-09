#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    string movie_name;
    float adult_price, child_price, perc;
    int adult_sold, child_sold;

    // Taking input from user
    cout << "Enter movie name :" << endl;
    getline (cin, movie_name);

    cout << "Enter adult ticket price :" << endl;
    cin >> adult_price;

    cout << "Enter child ticket price :" << endl;
    cin >> child_price;

    cout << "Enter number of adult ticket sold :" << endl;
    cin >> adult_sold;

    cout << "Enter the number of child tickets sold :" << endl;
    cin >> child_sold;

    cout << "Enter the percentage of revenue to be donated :" << endl;
    cin >> perc;


    // calculation 
    int total_tickets = adult_sold + child_sold;
    float gross_amount = (adult_price*adult_sold) + (child_price*child_sold);
    float donate_amount = (perc * gross_amount) / 100;
    float net_sale = gross_amount - donate_amount;


    // displaying results
    cout<<"*************************************************************"<<endl;
    cout<<"Movie name: ................. "<<movie_name<<endl;
    cout<<"Number of tickets sold: .....      "<<total_tickets<<endl;
    cout<<"Gross amount: ............... "<<"$  "<< fixed << setprecision(2) << gross_amount<<endl;
    cout<<"Percentage of gross amount: .....  "<< fixed << setprecision(2) << perc<<" %" << endl;
    cout<<"Amount Donated: ............. "<<"$  "<< fixed << setprecision(2) << donate_amount<< endl;
    cout<<"Net Sale: .............       "<<"$  "<< fixed << setprecision(2)<<net_sale<< endl;

    return 0;
}    