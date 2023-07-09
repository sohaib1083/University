#include <iostream>
using namespace std;

class sales
{
    int sale_id;
    string item_name;
    int quantity;

public:
    sales()
    {
    }

    sales(int s, string n, int q)
    {
        sale_id = s;
        item_name = n;
        quantity = q;
    }

    sales(sales &s)
    {
        sale_id = s.sale_id;
        item_name = s.item_name;
        quantity = s.quantity;
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
    sales obj1(3278, "Transformer z4", 8);
    sales obj2;
    obj2 = obj1;
    cout << "Sale ID: " << obj2.get_sale_id() << endl;
    cout << "Item Name: " << obj2.get_item_name() << endl;
    cout << "Quantity: " << obj2.get_quantity() << endl;
}