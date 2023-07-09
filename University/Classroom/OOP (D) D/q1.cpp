#include<iostream>

using namespace std;

class num{
	public:
		int x;
	public:
		num()
		{
			x=0;
		}
		num(int x)
		{
			this -> x=x;
		}
num operator--()
{

	x=x*4;
	
	return *this;
}

num operator --(int)
{
	num n1;
	n1.x=x/4;
	return n1;
}
int get_num()
{
return x;	
}		
};
int main()
{
	num a(32),b;
	b=a--;
	cout<<b.x<< " ";
	
	num c(8),d;
	d=--c;
	cout<<d.x;
	
}
