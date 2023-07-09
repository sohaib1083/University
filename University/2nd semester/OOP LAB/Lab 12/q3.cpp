#include <iostream>
#include <cstring>
using namespace std;

template <class X>
class sum{
	int size;
	X *a;
	public:
	sum()
	{
		
	}
	sum(int size, X array[])
	{
		this -> size = size;
		a= array;
	}
		
	X Cal_sum()
	{
		X s = a[0];
		
		for (int i = 1; i< size; i++)
		{
			s += a[i];
		}
		return s;
	}
		
};


int main (void)
{
	int a1[] = {1, 2, 3, 3, 2};
	int elements = (sizeof(a1))/(sizeof(a1[0]));
	
	sum<int> obj1(elements, a1);
	cout<<obj1.Cal_sum();
	
	double a2[] = {1.8, 1.2, 74.9, 4.8};
	int elements2 = (sizeof(a2))/(sizeof(a2[0]));
	
	sum<double> obj2(elements2, a2);
	cout<< endl<< obj2.Cal_sum();
}
