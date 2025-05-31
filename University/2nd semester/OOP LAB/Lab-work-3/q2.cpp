# include <iostream>

using namespace std;

class Date{
    int month; 
    int day;
    int year;

    public:
    void displayDate (void)
    {
        cout<< day<< "\n/"<< month<< "/"<< year<< endl;
    }
    void set(void)
    {
        cout<< "Enter day:";
        cin >> day;
        cout<< "\nEnter month:";
        cin>> month;
        cout<< "\nEnter year:";
        cin>> year;
    }

};

int main (void)
{
    Date test;
    test.set();
    test.displayDate();

    return 0;
}


