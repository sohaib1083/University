#include <iostream>
#include <iomanip>
using namespace std;

class item
{
    int item_num;
    string name;
    float price;

public:
    void seti(int item_num)
    {
        this->item_num = item_num;
    }
    void setn(string name)
    {
        this->name = name;
    }
    void setp(float price)
    {
        this->price = price;
    }

    int geti(void)
    {
        return item_num;
    }
    string getn(void)
    {
        return name;
    }
    float getp(void)
    {
        return price;
    }
};

class discount : public item
{
    float discount;

public:
    void setd(float discount)
    {
        this->discount = discount;
    }

    void set_item(int item_num, string name, float price, float discount)
    {
        seti(item_num);
        setn(name);
        setp(price);
        setd(discount);
    }

    float getd(void)
    {
        return discount;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of customers: ";
    cin >> n;

    discount *ptr;
    ptr = new discount[n];

    int item_num;
    string name;
    float price;
    float discount, total_amount = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for item #" << i + 1 << " : " << endl;
        cout << "Enter item number for item #" << i + 1 << " : ";
        cin >> item_num;

        cout << "Enter name for item #" << i + 1 << " : ";
        fflush(stdin);
        getline(cin, name);

        cout << "Enter price for item #" << i + 1 << " : ";
        cin >> price;

        cout << "Enter discount for item #" << i + 1 << " : ";
        cin >> discount;

        total_amount = total_amount + (-1 * (price * ((discount/100)-1)));

        (ptr + i)->set_item(item_num, name, price, discount);
    }

    // output bill
    cout<< endl<< endl;
    cout << "Item number" << setw(20) << "Name" << setw(20) << "Price" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << (ptr + i)->geti() << setw(22) << (ptr + i)->getn() << setw(20) << (ptr + i)->getp() << endl;
    }

    cout<< endl<< "The total amount payable is : "<< total_amount;
}