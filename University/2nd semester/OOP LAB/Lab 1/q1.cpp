#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float weight;
	
	cout << "Enter the weightage inn kgs:"<< endl;
	cin >> weight;
	
	float pounds = weight * 2.2;
	
	cout << "The weight in pounds is :" << fixed << setprecision(2) << pounds << endl;
	cout << "The weight in kgs is :" << weight << endl; 
	
	return 0;
}
