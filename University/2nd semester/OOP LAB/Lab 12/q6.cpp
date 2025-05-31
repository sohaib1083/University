#include <iostream>
using namespace std;

template <class T>
void square (T a[], int size)
{
	T b[10];
	
	for (int i = 0; i<size; i++)
	{
		b[i] = (a[i] * a[i]);
	}
	cout<< "original array: ";
	for (int i = 0; i<size; i++)
	{
		cout<< a[i]<< " ";
	}
	
	cout<< "\nsquared array: ";
	for (int i = 0; i<size; i++)
	{
		cout<< b[i]<< " ";
	}	
}

int main (void)
{
	int array[3] = {1, 5, 9};
	
	square(array, 3);
	
}

