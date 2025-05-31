#include <iostream>
using namespace std;

class User
{
    int a;
    string n;

    public:
        void set_a(int x)
        {
            a = x;
        }
        int get_a()
        {
            return a;
        }
    
        void set_n(string y)
        {
            n = y;
        }
        string get_n()
        {
            return n;
        }
};

int main()
{
    class User U1;
    U1.set_n("Teo");
    U1.set_a(24);

    cout << "My name is " << U1.get_n() << " and I'm " << U1.get_a() << " Years old.";

    return 0;
}
