#include <iostream>
using namespace std;

class quad
{
public:
    float l1, l2, l3, l4;
    virtual float area() = 0;
    void set_lenght(float a, float b, float c, float d)
    {
        l1 = a;
        l2 = b;
        l3 = c;
        l4 = d;
    }
};

class rectangle : public quad
{
public:
    float area()
    {
        return l1 * l2 * l3 * l4;
    }
    void toplevel(float a, float b, float c, float d)
    {
        set_lenght(a, b, c, d);
    }
};

int main(void)
{
    rectangle obj1;
    obj1.set_lenght(2, 2, 2, 2);
    cout << obj1.area() << endl;
    rectangle *ptr = &obj1;
    ptr->toplevel(2, 3, 4, 5);
    cout << ptr->area();
    return 0;
}