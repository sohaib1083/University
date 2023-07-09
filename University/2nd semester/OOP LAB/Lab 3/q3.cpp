#include <iostream>
#include <string>

using namespace std;

class Invoice
{
    string number;
    string description;
    int q;
    float price;

public:
    void setn(string n)
    {
        number = n;
    }

    void setd(string d)
    {
        description = d;
    }

    void setq(int qt)
    {
        if (qt < 0)
        {
            q = 0;
        }

        else
        {
            q = qt;
        }
    }

    void setp(float p)
    {
        if (p < 0)
        {
            price = 0;
        }

        else
        {
            price = p;
        }
    }

    float getT()
    {
        return (q * price);
    }

    string getIp_number()
    {
        return number;
    }

    string getIp_description()
    {
        return description;
    }

    int getq()
    {
        return q;
    }

    float getp()
    {
        return price;
    }
};

int main()
{
    Invoice obj1;
    string name, desc;
    int quantity;
    float price;

    cout << "Enter the part number: ";
    fflush(stdin);
    getline(cin, name);
    obj1.setn(name);

    cout << "Enter the part discription: ";
    fflush(stdin);
    getline(cin, desc);
    obj1.setd(desc);

    cout << "Enter the quantity of the item being purchased: ";
    cin >> quantity;
    obj1.setq(quantity);

    cout << "Enter price per item: ";
    cin >> price;
    obj1.setp(price);

    system("cls");
    cout << "Part Number: " << obj1.getIp_number() << endl;
    cout << "Part Description: " << obj1.getIp_description() << endl;
    cout << "Quantity: " << obj1.getq() << endl;
    cout << "Price per item: " << obj1.getp()<<endl;
    cout<<"Total Amount: "<<obj1.getT()<<endl;
}