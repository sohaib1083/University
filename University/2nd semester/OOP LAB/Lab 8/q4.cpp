#include <iostream>
using namespace std;


class stud{
	public:
int mult (int x, int y)
{
	return x*y;
}

int mult (int x, int y, int z)
{
	return x*y*z;
}

double mult (double x, double y, double z)
{
	return x*y*z;
}

double mult (double x, double y)
{
	return x*y;
}	
};



int main (void)
{
	stud obj;
	cout<< obj.mult(5, 6)<< " "<< obj.mult (5, 6, 7) << " "<< obj.mult (2.3, 2.4)<< " "<< obj.mult (2.3, 6.7, 7.8);
	return 0;
}