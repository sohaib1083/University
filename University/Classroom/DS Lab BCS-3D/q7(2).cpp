#include<iostream>
using namespace std;
class car{
    int door;
    int engine_capacity;
    int *ptr;// number of gears
    public:
    car()
    {   
    }
    car(int d, int e, int num_gears)
    {
        door=d;
        engine_capacity=e;
        ptr= new int;
        *ptr=num_gears;
    }
    car(const car &s)
    {
        door=s.door;
        engine_capacity=s.engine_capacity;
        ptr = new int;
        *(ptr)= *(s.ptr);
    }
    void show_car()
    {
        cout<<endl<< door<< " "<< engine_capacity<< " "<< *ptr<<" "<< endl;
    }
    void  operator=(const car &s)
    {
        cout<< "im in operator";
        door=s.door;
        engine_capacity=s.engine_capacity;
        ptr = new int;
        *(ptr)= *(s.ptr);
    }
    ~car()
    {
        delete ptr;
    }
};
int main (void)
{
    car c1(2, 660, 3);
    car c2 = c1;
    c1.show_car();
    c2.show_car();

    car c3(4, 1000, 5);
    car c4;
    c4=c3;
    c4.show_car();
    return 0;
}