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

    int getcode (void)
    {
        return barcode;
    }
    string getname(void)
    {
        return name;
    }

    void scanner ()
    {
        cout<< "name:";
        fflush(stdin);
        getline (cin, name);
        cout<< "barcode:";
        cin>> barcode;
    }

    void printer ()
    {
        cout<< "name: "<< name<< endl << "barcode: "<< barcode;
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
        cout<< "unit price: "<< unit_price<< endl;
        Product :: printer();
    }
    void set_pack (int unit, string name, int barcode)
    {
        setcode (name, barcode);
        unit_price = unit;
    }
    int getprice()
    {
        return unit_price;
    }
    void get_pack ()
    {
        Product :: getcode();
        cout<< "Name: "<< getname()<< endl << " barcode: "<< getcode()<< endl<< " unit: "<< unit_price<< endl;
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
        cout<< "weight: "<< weight<< " price: "<< pricekg<< " " ;
        Product :: printer();
    }

    void set_fresh(float w = 1, float p = 1, string name = "item", int barcode = 101)
    {
        weight = w;
        pricekg = p;
        setcode (name, barcode);
    }

    float  getw ()
    {
        return weight;
    }
    float getp()
    {
        return pricekg;
    }
    
};

int main (void)
{
    Product o1(123, "bat");
    o1.printer();
    cout<< endl<< endl;

    Product o2;
    o2.scanner();
    o2.printer();
    cout<< endl<< endl;

    Product o3;
    o3.setcode("box", 3);
    cout<<"barcode: " <<o3.getcode()<< " name: "<<o3.getname()<< endl;
    cout<< endl;

    prepack b1(12, "orange", 1009);
    b1.printer();
    cout<< endl<< endl;

    prepack b2;
    b2.scanner();
    b2.printer();
    cout<< endl<< endl;

    prepack b3;
    b3.set_pack(123, "chips", 1002);
    cout<<"barcode: " <<b3.getcode()<< " name: "<<b3.getname()<< " unit price: "<< b3.getprice() << endl;
    cout<< endl<< endl;
    
    fresh c1(12.3, 1.2, "tomatoes", 1239);
    c1.printer();
    cout<< endl<< endl;

    fresh c2;
    c2.scanner();
    c2.printer();
    cout<< endl<< endl;

    fresh c3;
    c3.set_fresh(12.3, 1.0, "tomatoes", 27337);
    cout<<" barcode: " <<c3.getcode()<< " name: "<<c3.getname()<< " weight: "<< c3.getw()<<" price per kg: "<< c3.getp() << endl;
    return 0;
}