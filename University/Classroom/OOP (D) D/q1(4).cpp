#include <iostream>
#include <string>
using namespace std;

class phone_num
{
    string area_code, exchange, num;

public:
    phone_num(string n)
    {
        area_code = n.substr(0, 3);
        exchange = n.substr(3, 4);
        num = n.substr(7, 10);
    }

    string geta(void)
    {
        return area_code;
    }

    string gete(void)
    {
        return exchange;
    }

    string getn(void)
    {
        return num;
    }
};

int main(void)
{
    string num;
    cout << "\nEnter a 11 digit number:";
    cin >> num;

    phone_num obj1{num};

    cout << "\nprogram output:"
         << "\nYour area code is: " << obj1.geta()
         << "\nExchange code is : " << obj1.gete()
         << "\nYour consumer No is : " << obj1.getn();

    return 0;
}