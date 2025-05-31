#include <iostream>
#include <iomanip>

using namespace std;

class rectangle{
    float lenght = 1.0;
    float width = 1.0;

    public:
    void set_l(float a){
        if (a>0.0 && a<=20.0)
           lenght = a;
        else
            cout<< "error, changes not applied"<< endl;   
    }
    void set_w(float b){
        if (b>0.0 && b<=20.0)
           width = b;
        else
            cout<< "error, changes not applied"<< endl;
    }
    float get_l(){
        return lenght;
    }
    float get_w(){
        return width;
    }
    float area (){
        return lenght*width;
    }
    float perimeter(){
        return ((2*width)+(2*lenght));
    }
};


int main (void)
{
    rectangle r;

    float len, wit;
    cout<< "Enter lenght: ";
    cin>> len;
    r.set_l(len);

    cout<< "Enter widht: ";
    cin>> wit;
    r.set_w(wit);

    cout<< "\nThe lenght is : "<< setw(6) << r.get_l();
    cout<< "\nThe widht is : "<< setw(7) << r.get_w();
    cout<< "\nThe area is : "<< setw(8) << r.area();
    cout<< "\nThe perimeter is : "<< setw(3) <<r.perimeter();

    return 0;
}