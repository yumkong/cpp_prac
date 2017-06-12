//virtual destructor of a class
#include <iostream>
using namespace std;
class Father
{
public:
    Father() {}
	// the destructor of Father must be virtual so as to
	// use virutal func to destruct both child var and father var
	//  otherwise only destruct father
	virtual ~Father()
	{
		cout << "Destructor Father" << endl;
	}
};

class Child:public Father
{
public:
    ~Child()
	{
		cout << "Destructor Child" << endl;
	}
};

int main()
{
	Father *pa;
	pa = new Child;
	delete pa; //"Destructor Child" + "Destructor Father"
	return 0;
}