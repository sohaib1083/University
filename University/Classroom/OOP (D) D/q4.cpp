#include <iostream>
using namespace std;

class poly{
	int cof, exp;
	public:
	poly()
	{	
	}	
	poly(int c, int e)
	{
		cof = c;
		exp = e;
	}
	~poly()
	{
	}
	void setc(int c)
	{
		cof = c;
	}
	void sete(int e)
	{
		exp = e;
	}
	int getc()
	{
		return cof;
	}
	int gete()
	{
		return exp;
	}
	void print_poly()
	{
		cout<<endl<< cof<< "x^"<<exp;
	}
	
	poly operator +(poly &x)
	{
		poly temp;
		if (x.exp == exp)
		{
			temp.cof = x.cof + cof;
			temp.exp = exp;
		}
		return temp; 
	}
	
	poly operator -(poly &x)
	{
		poly temp;
		if (x.exp == exp)
		{
			temp.cof = cof - x.cof;
			temp.exp = exp;
		}
		return temp; 
	}
	
	void operator =(poly &x)
	{
		cof = x.cof;
		exp = x.exp;
	}
	
	poly operator *(poly &x)
	{
		poly temp;
		temp.cof = cof * x.cof;
		temp.exp = exp + x.exp;
		return temp; 
	}
	
	poly operator +=(poly &x)
	{
		if (x.exp == exp)
		{
			cof = x.cof + cof;
		}
	}
	
	poly operator -=(poly &x)
	{
		if (x.exp == exp)
		{
			cof = cof - x.cof;
		}
	}
	
	poly operator *=(poly &x)
	{
		cof = cof * x.cof;
		exp = exp + x.exp;
	}	
};


int main (void)
{
	poly p1(2, 3);
	poly p2(3, 3);
	poly p3 = p1+p2;
	p3.print_poly();
	
	poly p4(2, 3);
	poly p5(3, 3);
	poly p6 = p5-p4;
	p6.print_poly();
	
	poly p7(2, 3);
	poly p8(3, 3);
	p7 = p8;
	p7.print_poly();
	
	
	poly p9(2, 3);
	poly p10(3, 3);
	poly p11 = p9*p10;
	p11.print_poly();
	

	poly p12(2, 3);
	poly p13(3, 3);
	p13 += p12;
	p13.print_poly();
	
	
	poly p14(2, 3);
	poly p15(3, 3);
	p15 -= p14;
	p15.print_poly();
	
	
	poly p16(2, 3);
	poly p17(3, 3);
	p17 *= p16;
	p17.print_poly();
	return 0;
}
