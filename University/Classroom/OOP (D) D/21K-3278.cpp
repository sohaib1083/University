#include <iostream>
#include <string>
using namespace std;

class Product{
    string name;
    int barcode;
    public:
    Product(int barcode = 1, string name = "item")
    {
        this -> name = name;
        this -> barcode = barcode;
    }
    void setcode(string name, int barcode)
    {
        
        this -> name = name;
        this -> barcode = barcode;
    }

    void getcode (void)
    {
        cout<< "name: "<< name<< endl<< "barcode: "<< barcode;
    }

    void scanner ()
    {
        cout<< "nmae:";
        getline (cin, name);
        cout<< "barcode:";
        cin>> barcode;
    }

    void printer ()
    {
        cout<< "name: "<< name<< endl<< "barcode: "<< barcode;
    }
};


class prepack : public Product {
    int unit_price;
    public:
    prepack(int unit = 10, string name = "item", int barcode = 101) : Product (barcode, name)
    {
        unit_price = unit;
    }
    void scanner()
    {
        cout<< "unit price:";
        cin>> unit_price;
        Product :: scanner();
    }
    void printer ()
    {
        cout<< "the unit price: "<< unit_price;
        Product :: printer();
    }

};

class fresh : public Product {
    float weight, pricekg;
    public:
    fresh(float w = 1, float p = 1, string name = "item", int barcode = 101) : Product (barcode, name)
    {
        weight = w;
        pricekg = p;
    }
    void scanner()
    {
        cout<< "weight & price per kg:";
        cin>> weight>> pricekg;

        Product :: scanner();
    }
    void printer ()
    {
        cout<< "weight: "<< weight<< "price: "<< pricekg;
        Product :: printer();
    }
    
};

int main (void)
{
    Product o1(123, "bat"), o2, o3;
    prepack b1 (7387, "Samosa"), b2, b3;
    fresh c1(5, 43234, "ice-cream"), c2, c3;

    return 0;
}