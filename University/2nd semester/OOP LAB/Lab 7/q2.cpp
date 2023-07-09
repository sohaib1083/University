#include <iostream>
using namespace std;

class mamal
{
public:
    void fun()
    {
        cout << "Im mamal" << endl;
    }
};

class marine
{
public:
    void fun()
    {
        cout << "Im marine" << endl;
    }
};

class blueWhale : public mamal, public marine
{
public:
    void fun()
    {
        cout << "Im both" << endl;
    }
};

int main(void)
{
    mamal obj1;
    marine obj2;
    blueWhale obj3;

    obj1.fun();
    obj2.fun();
    obj3.fun();
    obj3.mamal ::fun();
    obj3.marine ::fun();
}
