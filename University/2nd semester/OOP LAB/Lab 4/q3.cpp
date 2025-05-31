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
        sale_id = 0;
        item_name = "any item";
        quantity = 3;
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
};

int main(void)
{
}