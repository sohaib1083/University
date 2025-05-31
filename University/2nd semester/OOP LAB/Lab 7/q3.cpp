#include <iostream>
#include <string>
using namespace std;
class vehicle
{
private:
    float mileage;
    float price;

public:

vehicle(float mileage, float price)
{
    this -> mileage = mileage;
    this -> price = price;
}
    void set_mileage(float m1)
    {
        mileage = m1;
    }

    void set_price(float p1)
    {
        price = p1;
    }

    float get_mileage()
    {
        return mileage;
    }

    float get_price()
    {
        return price;
    }
};

class Car : public vehicle
{
private:
    float cost;
    int warranty;
    int seats;
    string fuel_type;

public:

Car (float cost, int warranty, int seats, string fuel_type, float mileage, float price) : vehicle(mileage, price)
{
    this -> cost = cost;
    this -> warranty = warranty;
    this -> seats = seats;
    this -> fuel_type = fuel_type;
}
    void set_cost(float c)
    {
        cost = c;
    }

    void set_warranty(int w)
    {
        warranty = w;
    }

    void set_seats(int s)
    {
        seats = s;
    }

    void set_fuel_type(string t)
    {
        fuel_type = t;
    }

    float get_cost()
    {
        return cost;
    }

    int get_warranty()
    {
        return warranty;
    }

    int get_seats()
    {
        return seats;
    }

    string get_fuel_type()
    {
        return fuel_type;
    }
};

class Bike : public vehicle
{
private:
    int nc;
    int ng;
    string cooling_type;
    string wheel_type;
    int tank_size;

public:
Bike (int nc, int ng, string cooling_type, string wheel_type, int tank_size, float mileage, float price) : vehicle(mileage, price)
{
    this -> nc = nc;
    this -> ng = ng;
    this ->cooling_type = cooling_type;
    this -> wheel_type  = wheel_type;
    this -> tank_size = tank_size;
}
    void set_nc(int n)
    {
        nc = n;
    }

    void set_ng(int g)
    {
        ng = g;
    }

    void set_cooling_type(string ct)
    {
        cooling_type = ct;
    }

    void set_wheel_type(string wt)
    {
        wheel_type = wt;
    }

    void set_tank_size(int s)
    {
        tank_size = s;
    }

    int get_nc()
    {
        return nc;
    }

    int get_ng()
    {
        return ng;
    }

    string get_cooling_type()
    {
        return cooling_type;
    }
    
    string get_wheel_type()
    {
        return wheel_type;
    }

    int get_tank_size()
    {
        return tank_size;
    }
};

class audi : public Car {
    private:
    string model_type;

    public:
    audi(string model_type,float cost, int warranty, int seats, string fuel_type, float mileage, float price) : Car(cost, warranty, seats, fuel_type, mileage, price)
    {
        this -> model_type = model_type;
    }
    void set_model_type(string m)
    {
        model_type = m;
    }
    
    string get_model_type()
    {
        return model_type;
    }
};

class ford : public Car {
    private:
    string model_type;

    public:
    ford(string model_type,float cost, int warranty, int seats, string fuel_type, float mileage, float price) : Car(cost, warranty, seats, fuel_type, mileage, price)
    {
        this -> model_type = model_type;
    }
    void set_model_type(string m)
    {
        model_type = m;
    }
    
    string get_model_type()
    {
        return model_type;
    }
};

class Bajaj : public Bike{
    private:
    string make_type;
    
    public:
    Bajaj(string make_type, int nc, int ng, string cooling_type, string wheel_type, int tank_size, float mileage, float price) : Bike(nc, ng, cooling_type, wheel_type, tank_size, mileage, price)
    {
        this -> make_type = make_type;
    }  
    void set_make_type(string m)
    {
        make_type = m;
    }

    string get_make_type()
    {
        return make_type;
    }
};

class TVS : public Bike{
    private:
    string make_type;
    
    public:
    TVS(string make_type, int nc, int ng, string cooling_type, string wheel_type, int tank_size, float mileage, float price) : Bike(nc, ng, cooling_type, wheel_type, tank_size, mileage, price)
    {
        this -> make_type = make_type;
    }  
    void set_make_type(string m)
    {
        make_type = m;
    }

    string get_make_type()
    {
        return make_type;
    }
};

int main()
{
    audi o1("A3", 36000, 2019, 4, "petrol", 23000, 23498.9);
    ford o2("Jenny", 99000, 2030, 6, "deisel", 23000, 23.6554);
    Bajaj o3("road", 32, 12, "dual-fan", "4-wheel", 12, 13.6, 5365.4);
    TVS o4("off-road", 12, 14, "single-fan", "2-wheel", 13, 19.687, 87285.44);
    
    cout<<"For Audi: "<<endl<<endl;
    cout<<"Model Type: "<<o1.get_model_type()<<endl;
    cout<<"Ownership cost: "<<o1.get_cost()<<endl;
    cout<<"Warranty : "<<o1.get_warranty()<<endl;
    cout<<"Seats: "<<o1.get_seats()<<endl;
    cout<<"Fuel Type: "<<o1.get_fuel_type()<<endl;
    cout<<"Mileage: "<<o1.get_mileage()<<endl;
    cout<<"Price: "<<o1.get_price()<<endl;

    cout<<endl;
    cout<<"For Ford: "<<endl<<endl;
    cout<<"Model Type: "<<o2.get_model_type()<<endl;
    cout<<"Ownership cost: "<<o2.get_cost()<<endl;
    cout<<"Warranty : "<<o2.get_warranty()<<endl;
    cout<<"Seats: "<<o2.get_seats()<<endl;
    cout<<"Fuel Type: "<<o2.get_fuel_type()<<endl;
    cout<<"Mileage: "<<o2.get_mileage()<<endl;
    cout<<"Price: "<<o2.get_price()<<endl;

    cout<<endl;
    cout<<"For  Bajaj: "<<endl<<endl;
    cout<<"Make Type: "<<o3.get_make_type()<<endl;
    cout<<"Number of cylinders: "<<o3.get_nc()<<endl;
    cout<<"Number of gears: "<<o3.get_ng()<<endl;
    cout<<"Cooling type: "<<o3.get_cooling_type()<<endl;
    cout<<"Tank Size: "<<o3.get_tank_size()<<endl;
    cout<<"Mileage: "<<o3.get_mileage()<<endl;
    cout<<"Price: "<<o3.get_price()<<endl;
    
    cout<<endl;
    cout<<"For TVS: "<<endl<<endl;
    cout<<"Make Type: "<<o4.get_make_type()<<endl;
    cout<<"Number of cylinders: "<<o4.get_nc()<<endl;
    cout<<"Number of gears: "<<o4.get_ng()<<endl;
    cout<<"Cooling type: "<<o4.get_cooling_type()<<endl;
    cout<<"Tank Size: "<<o4.get_tank_size()<<endl;
    cout<<"Mileage: "<<o4.get_mileage()<<endl;
    cout<<"Price: "<<o4.get_price()<<endl; 
}