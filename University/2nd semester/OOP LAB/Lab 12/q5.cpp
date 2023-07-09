#include <iostream>
using namespace std;

template <class T>
T largest(T x1, T x2, T x3)
{
	if (x1>x2 && x1>x3)
	{
		return x1;
	}
	else if (x2> x1 && x2 > x3)
	{
		return x2;
	}
	else if (x3 > x2 && x3 > x1)
	{
		return x3;
	}
}

int main (void)
{
	double i1, i2, i3;
	cin>> i1>> i2>> i3;
	
	cout<< largest(i1, i2, i3);
}
