#include <iostream>
#include <string>
using namespace std;
class Sales
{

private:
    int sale_id, quantity;
    string item_name;

public:
    Sales()
    {
        sale_id = 0;
        item_name = "any item";
        quantity = 0;
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
    Sales obj;
    cout << "Displaying sales object: " << endl;
    cout << "Sales ID = " << obj.get_sale_id() << "   Item Name = " << obj.get_item_name() << "   quantity = " << obj.get_quantity() << endl;
}