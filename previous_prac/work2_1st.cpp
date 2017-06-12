#include <iostream>
using namespace std;

class Basic 
{
private:
	int nBval;
public:
	void Print()
	{
		cout << "nBval = " << nBval << endl;
	}
	void Fun()
	{
		cout << "B::Fun" << endl;
	}
	Basic()
	{
		nBval = 0;
	}
	Basic(int n)
	{
		nBval = n;
	}
};
//derivative class always have implicit member var and func of basic class
class Derivative:public Basic
{
private:
    int nDval;
public:
    void Print()
	{
		Basic::Print();
		cout << "nDval = " << nDval << endl;
	}
	void Fun()
	{
		cout << "D::Fun" << endl;
	}
	// this seem to create an implict accompaning member variable: nBval
	// initialize with 3*n the same time when D class is constructed
	Derivative(int n):Basic(3*n)
	{
		nDval = n;
	}
};

int main()
{
	Basic *pb;
	Derivative *pd;
    Derivative d(4); //nDval=4, nBval=12
	d.Fun(); //D::Fun

    pb = new Basic(2);
    pd = new Derivative(8); //nBval=24  nDval=8	
	pb->Fun();//B::Fun
	pd->Fun(); //D::Fun
	pb->Print(); //nBval=2
	pd->Print(); //nBval=24, nDval=8
	pb = &d; // point to the implict var (12) and func(B::Fun) of d
	pb->Fun(); // B::Fun => call basic class's fun
	// 12 => call basic class's print => but nBval is initialize when d is created
	pb->Print(); 
	return 0;
}

