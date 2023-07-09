#include<iostream>
using namespace std;

void metersAndCentTofeetAndInches(float &m, float &c)	//reference variables
{
	float inch, feet;
	
	c += (m * 100);
	
	inch = c / 2.54;
	feet = inch / 12;
	inch = (int)inch % 12;
	
	cout<<endl<<"Your height in feets and inches is:"<<endl;
	cout<<"Feet = "<<(int)feet;
	cout<<endl<<"Inch = "<<inch<<endl<<endl;
}

int feetAndInchesToMetersAndCent(float feet, float inch)	//normal variables
{
	float meter, cent;
	
	if (feet >= 0 && inch >= 0)
	{
		inch += 12 * feet;
	}
	else
	{
		cout<< "feet and inches cannot be in negative."<< endl;
		return -1;
	}
	
	cent = inch * 2.54;
	
	meter = cent / 100;
	cent = (int)cent % 100;
	
	cout<<endl<<"Your height in meters and centimeters is:"<<endl;
	cout<<"Meter = "<<(int)meter;
	cout<<endl<<"Centimeter = "<<cent+2<<endl<<endl;
}

void showChoices(void)
{
	int choice;
	float inch, feet, meter, cent;
	do
	{
		cout<<"What do you want to do? Select from the options below."<<endl;
		cout<<"1. Convert feet and inches to meters and centimeters."<<endl;
		cout<<"2. Convert meters and centimeters to feet and inches."<<endl;
		cout<<"3. Exit"<<endl;
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter your height in feets and inches."<<endl;
			cout<<"Feet: ";
			cin>>feet;
			cout<<"Inch: ";
			cin>>inch;
			feetAndInchesToMetersAndCent(feet, inch);
		}
		else if(choice==2)
		{
			cout<<"Enter your height in meters and centimeters."<<endl;
			cout<<"Meter: ";
			cin>>meter;
			cout<<"Centimeter: ";
			cin>>cent;
			metersAndCentTofeetAndInches(meter, cent);
		}
		else if(choice<1 || choice>3)
		{
			cout<<"Wrong choice."<<endl;
		}
	}while(choice!=3);
}

int main()
{
	showChoices();
}
