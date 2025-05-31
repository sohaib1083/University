#include <iostream>
#include <cstring>
using namespace std;

template <class X, class Y>
class example{
	X var1;
	Y var2;
	
	public:
	example(X v1, Y v2)
	{
		var1 = v1;
		var2 = v2;
		//cout<< var1<< var2;
	}
	void addition()
	{
		cout<< var1+var2;
	}	
};

template <>
class example <char*, char*>{
	char var1[30]; 
	char var2[30];
	public:
	example(char *v1, char *v2)
	{
		strcpy(var1, v1);
		strcpy(var2, v2);
	}	
	void addition ()
	{
	char *s = strcat(var1, " ");
	char *final = strcat(s, var2);
	cout<< final;	
	
	}
};


int main (void)
{
	example<int, float> e1(10, 0.23);
	e1.addition();
	cout<< endl;
	example<char*, char*> e2("Now", "Then");
	e2.addition();
	return 0;
}

