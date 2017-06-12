#include <iostream>
using namespace std;

class Father
{
private:
    int nVal;
public:
    void Fun()
	{
		cout << "Father::Fun" << endl;
	}
	void Do()
	{
	    cout << "Father::Do" << endl;	
	}
};

class Child:public Father
{
public:
    //void Fun()
	//{
	//	cout << "Child::Fun" << endl;
	//}
    virtual void Do()
	{
		cout << "Child::Do" << endl;
	}
};

class Grandchild:public Child
{
public:
    void Do()
	{
		cout << "Grandchild::Do" << endl;
	}
	void Fun()
	{
		cout << "Grandchild::Fun" << endl;
	}
};

void Call(Child &p)
{
	p.Fun();
	p.Do();
}

int main()
{
	Grandchild gc;
	//Fun (not virtual func, so if child class ifself have Fun, use it),
	// otherwise use Father::Fun.) 
	//Do is virtual func => determine which one to use at running time
	// here since the real param is from Grandchild, directly use Grandchild's Do
	Call(gc);
	return 0;
}