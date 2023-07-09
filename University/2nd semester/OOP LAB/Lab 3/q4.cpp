#include<iostream>
#include<iomanip>

using namespace std;

class coffee {
    int LBox;
    int MBox;
    int SBox;
    int bags;
    float b1;
    float cl;
    float cm;
    float cs;
    
    public: 
    coffee()
    {
        LBox = 0;
        MBox = 0;
        SBox =0;
        b1 = 5.50;
        cl = 1.80;
        cm = 1.00;
        cs = 0.60;
    }
    
    void setb(int b)
    {
        bags = b;

        while (b > 0)
        {
            if(b >= 20)
            {
            LBox = LBox + 1;
            b = b - 20;
            }
			
            else if (b > 5 && b <= 20)
            {
            MBox = MBox + 1;
            b = b - 10;
            }
    
            else if(b > 0 && b <=5)
            {
            SBox  = SBox + 1;
            b = b - 5;
            } 
        }

    }

    void set_LBox(int l)
    {
        LBox = l;
    }

    void set_MBox(int m)
    {
        MBox = m;
    }
    

    void set_SBox(int s)
    {
        SBox = s;
    }

    int getb()
    {
        return bags;
    }

    int get_LBox()
    {
        return LBox;
    }

    int get_MBox()
    {
        return MBox;
    }

    int get_SBox()
    {
        return SBox;
    }

    float get_bag1_cost()
    {
        return b1;
    } 

    float get_LBox_cost()
    {
        return (LBox * cl);
    }

    float get_MBox_cost()
    {
        return (MBox * cm);
    }

    float get_SBox_cost()
    {
        return (SBox * cs);
    }

    float cost_of_boxes()
    {
        float tcb;
        return (LBox * cl) + (MBox * cm) + (SBox * cs);
        return tcb;
    }

    float costb()
    {
        return (bags * b1);
    }

    float total()
    {
        return ((LBox * cl) + (MBox * cm) + (SBox * cs) + (bags * b1));
    }


};

int main(void)
{

    cout<< fixed << setprecision(2);
    coffee o1;
    int bag;
    float price; 
    
    cout<<"Enter the number of bags: ";
    cin>>bag;

    o1.setb(bag);

    cout<<"Number of bags ordered: "<<o1.getb()<< " .The cost of Order: $"<<o1.costb()<<endl;
    cout<<"Boxes used: "<<endl;

    cout<< setw(10) <<o1.get_LBox()<<" Large box  -   $"<< setw(10)<< o1.get_LBox_cost()<<endl;  
    cout<< setw(10) <<o1.get_MBox()<<" Medium box -   $"<< setw(10) <<o1.get_MBox_cost()<<endl;
    cout<< setw(10) <<o1.get_SBox()<<" Small box  -   $"<< setw(10) <<o1.get_SBox_cost()<<endl;

    cout<<"Your total cost is: $"<<o1.total()<<endl;
}