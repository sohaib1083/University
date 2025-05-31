#include <iostream>
using namespace std;

class triple
{
    float x, y, z;

public:
    void setx(float x1)
    {
        x = x1;
        if (x < 0)
        {
            throw -1;
        }
    }
    void sety(float y1)
    {
        y = y1;

        if (y < 0)
        {
            throw -1;
        }
    }
    void setz(float z1)
    {
        z = z1;

        if (z < 0)
        {
            throw -1;
        }
    }
    float getx()
    {
        return x;
    }

    float gety()
    {
        return y;
    }

    float getz()
    {
        return z;
    }

    triple(float x1, float y1, float z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }
    triple()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    triple operator+(triple &s)
    {
        triple temp;
        temp.x = x + s.x;
        temp.y = y + s.y;
        temp.z = z + s.z;
        return temp;
    }
    void output()
    {
        cout << "\nThe triple is(" << x << "," << y << "," << z << ")";
    }
    void assign()
    {
        float temp_z = z;
        z = x;
        x = y;
        y = temp_z;
    }
    void operator++(int)
    {
        x++;
        z++;
    }

    void call(float a, float b, float c)
    {
        setx(a);
        sety(b);
        setz(c);
    }

    void call_operator()
    {
        cout << "\nEnter data to set: ";

        float x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        call(x1, y1, z1);
    }
};

int main(void)
{
    float x1, y1, z1;
    triple obj;
    cout << "\nEnter data ";
    cin >> x1 >> y1 >> z1;
    try
    {
        obj.setx(x1);
        obj.sety(y1);
        obj.setz(z1);
    }
    catch (int e)
    {
        cout << " negative number not acceptable";
        main();
    }

    // part b
    triple o1(1, 9, 8), o2(1, 2, 3);
    triple o3 = o1 + o2;
    // part c
    o3.output();

    // part d
    o1.assign();
    o1.output();

    // part e
    o2++;
    o2.output();

    // part f
    o2.call_operator();

    return 0;
}