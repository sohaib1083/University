#include <iostream>

using namespace std;

int main (void)
{
    int acc_num;
    char code;
    float usage, charges = 0, day_usage, night_usage;

    cout<< "Enter account number:"<< endl;
    cin>> acc_num;

    cout<< "Enter service code:"<< endl;
    cin>> code;

    if (code == 'r' || code == 'R')
    {
        cout<<"Enter usage in minutes:"<< endl;
        cin>> usage;

        charges = 10.0;

        if (usage > 50)
        {
            charges = charges + (usage - 50) * 0.20; 

        }
    }
    else if (code == 'p' || code == 'P')
    {
        do{
        cout<< "Enter in minutes, the usage during day"<< endl;
        cin>> day_usage;

        cout<< "Enter in minutes, the usage during night"<< endl;
        cin>> night_usage;
        
        } while (day_usage < 0 && night_usage <0);

        charges = 25.0;

        if (day_usage > 75)
        {
            charges = charges + (0.10 * (day_usage -75));
        }
        if (night_usage > 100)
        {
            charges = charges + (0.05 * (night_usage - 100));
        }
    }
    else{
        cout<< "Error"<< endl;
    }


    // printing bill

    cout<< "***************** printing bill *******************"<< endl;
    cout<< "Account number : "<< acc_num<< endl;
    cout<< "Type of service : ";
    if (code == 'r' || code == 'R')
        cout<< "regular service"<< endl;
    else if (code == 'p' || code == 'P')
        cout<< "premium service"<< endl;
    cout<< "Number of minutes the service was used : ";
    if (code == 'r' || code == 'R')
        cout<< usage<< endl;
    else if (code == 'p' || code == 'P')
        cout<< day_usage + night_usage<< endl;
    cout<< "The amount due : " << charges<< endl;

    return 0;
}
