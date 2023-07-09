#include <iostream>
#include <string>
using namespace std;
class Sales
{

private:
    int sale_id, quantity;
    string item_name;

public:
    Sales(int sale_id, string item_name, int quantity)
    {
        this ->sale_id = sale_id;
        this -> quantity = quantity;
        this -> item_name = item_name;
    }

    void set_sale_id(int x)
    {
        sale_id = x;
    }

    void set_item_name(string y)
    {
        item_name = y;
    }

    void set_quantity(int z)
    {
        quantity = z;
    }

    int get_sale_id()
    {
        return sale_id;
    }

    string get_item_name()
    {
        return item_name;
    }

    int get_quantity()
    {
        return quantity;
    }
};

int main(void)
{
    int sale_id; 
    string item_name; 
    int quantity;

        cout<<"Enter Sale ID: ";
        cin>>sale_id;

        cout<<"Enter Item Name: ";
        fflush(stdin);
        getline(cin,item_name);

        cout<<"Enter Quantity: ";
        cin>>quantity;

    Sales obj(sale_id, item_name, quantity);

    cout << "Displaying sales object: " << endl;
    cout << "Sales ID = " << obj.get_sale_id() << "   Item Name = " << obj.get_item_name() << "   quantity = " << obj.get_quantity() << endl;
}