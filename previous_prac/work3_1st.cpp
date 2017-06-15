#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
	Complex()
	{
		cout << "default constructor called" << endl;
		real = 0.0;
		imag = 0.0;
	}
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
	cout << "1)" << endl;
	Complex c1(8,8); // direct constructor
	cout << "2)" << endl;
	Complex c2 = 9; // copy constructor
	cout << "3)" << endl;
	c1 = 9;  // assignment?
	c1.print();
	c2.print();
}