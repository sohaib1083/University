#include<iostream>
using namespace std;

class printclass;

class perimeter{
int l, b;
public:
	friend class printclass;

perimeter()
{
l=0;
b=0;
}

perimeter(int l, int b)
{
this -> l=l;
this -> b=b;
}

float cal()
{
	return l*b;
}

};

class printclass{
public: 
float func(perimeter a)
{
	return a.cal();
}
};

int main()
{
	perimeter obj(3,4);
	printclass c;
	cout<<c.func(obj);
}
