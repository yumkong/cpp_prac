#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
	Complex(int r)
	{
		cout << "int constructor called" << endl;
		real = r;
		imag = 0;
	}
	Complex(int r, int i)
	{
		real = r;
		imag = i;
	}
	void print()
	{
		cout << real << " + " << imag << "i" << endl;
	}
};

int main()
{
	Complex c1(8,8);
	Complex c2 = 9;
	c1 = 9;
	c1.print();
	c2.print();
}