#include <iostream>

class distance
{
private:
    float meters, inches, feet;

public:
    distance()
    {
        meters = 0.0;
        inches = 0.0;
        feet = 0.0;
    }

    ~distance()
    {
        std ::cout << "executing destructor, this proves that that object is killed";
    }

    void set_meters(float m)
    {
        meters = m;
    }

    void meter_To_FeetAndInches()
    {
        inches = meters * 39.3701;
        feet = inches / 12;
    }

    void display()
    {
        std ::cout << "Distance in meters: " << meters << std ::endl;
        std ::cout << "Distance in feets: " << feet << " feets" << std ::endl;
        std ::cout << "Distance in inches: " << inches << " inches" << std ::endl;
    }
};

int main()
{
    distance obj1;
    float m1;

    std ::cout << "Enter the distance (meters): ";
    std ::cin >> m1;
    system("cls");
    obj1.set_meters(m1);
    obj1.meter_To_FeetAndInches();
    obj1.display();
}