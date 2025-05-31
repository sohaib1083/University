#include <iostream>

using namespace std;

int main (void)
{
    int choice;
    int feets, inches, meters, centimeters;

    // calling function
    showChoices();

    cout<< "Enter your choice:";
    cin>> choice;

    switch (choice)
    {
        case 1:
        {
            cout<<"Enter feets:"<<endl;
            cin>> feets;
            cout<<"Enter inches:"<<endl;
            cin>> inches;

            feetAndInchesToMetersAndCent();
            break;
        }
        case 2:
        {
            cout<<"Enter meters:"<<endl;
            cin>> meters;
            cout<<"Enter centimeters:"<<endl;
            cin>> centimeters;
            metersAndCentTofeetAndInches();
            break;
        }
        case 3:
        {
            exit;
        }

    }



}

void feetAndInchesToMetersAndCent()
{

}

void metersAndCentTofeetAndInches()
{

}

void showChoices(void)
{
    cout<< "Enter 1 for conversion from feet & inches to meters & cents"<< endl;
    cout<< "Enter 2 for conversion from meters & cents to feet & inches"<< endl;
    cout<< "Enter 3 to exit"<< endl;

}