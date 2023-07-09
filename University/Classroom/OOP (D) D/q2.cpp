#include<iostream>
using namespace std;

class S{
int Area;

public:
int getarea()
{
return Area;
}

S()
{

}

S(int a){
Area=a;
}

S operator+(const S &o)
{
S o2;
o2.Area=this->Area+o.Area;
return o2;
}

};


int main(void)
{
S S1(10);
S S2(21);
S obj;
obj=S1+S2;

cout<<obj.getarea();
}
