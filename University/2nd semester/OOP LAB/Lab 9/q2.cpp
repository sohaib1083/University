#include <iostream>
using namespace std;


class rectangle;
class quad;

double calc_area(quad &s);

class quad{
    protected:
    float s1, s2, s3, s4;
    public:
    virtual double area() = 0;

    void set(float s1, float s2, float s3, float s4)
    {
        this -> s1 = s1;
        this -> s2 = s2;
        this -> s3 = s3;
        this -> s4 = s4;
    }
    //friend float rectangle :: toplevel(quad s)
};

class rectangle : public quad{
    public:
    double area()
    {
        return (s1*s2);
    }
    
};

int main (void)
{
    rectangle obj1 ,*ptr;
    ptr = &obj1;
    ptr->set(5, 4, 5, 4);
    float area = ptr->area();
    cout<< area<< endl;

    // using top level func
    cout<< calc_area(obj1);
    return 0;
}

double calc_area(quad &s)
{
    quad*ptr = &s;
    double a = ptr->area();
    return a;
}