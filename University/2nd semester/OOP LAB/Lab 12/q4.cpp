#include <iostream>
using namespace std;

template <class X, class Y>
class calculator{
	X var1;
	Y var2;
	public:
	calculator(X var1, Y var2)
	{
		this -> var1 = var1;
		this -> var2 = var2;
	}	
	void add()
	{
		cout<<endl<< var1+var2;
	}
	void sub()
	{
		cout<< endl<< var2-var1;
	}
	void mult()
	{
		cout<<endl<< var1*var2;
	}
	void div()
	{
		cout<< endl<<var1/(float)var2;
	}
};


int main (void)
{
	calculator<int, float> obj1(1, 2.5);
	obj1.add();
	obj1.sub();
	obj1.mult();
	obj1.div();
}
