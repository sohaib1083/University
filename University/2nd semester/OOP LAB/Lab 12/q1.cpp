#include <iostream>
using namespace std;

template <class T>
T BubbleSort(T b[], int size)
{
	T temp;
	
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (b[i] > b[j])
			{
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	}
	
	cout<< endl;
	for (int i = 0; i< size; i++)
	{
		cout<< b[i]<< " ";
	}
}

int main (void)
{
	
	int a[] = {7, 5, 4, 3, 9, 8, 6};
	int s = sizeof(a)/sizeof(a[0]);
	BubbleSort<int>(a, s);
	
	float a1[] = {4.3, 2.5, -0.9, 100.2, 3.0};
	int s1 = sizeof(a1)/sizeof(a1[0]); 
	BubbleSort<float>(a1, s1);
	
	return 0;
}
