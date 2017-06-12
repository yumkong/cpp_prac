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
	virtual void Do()
	{
		cout << "Father::Do" << endl;
	}
};

class Child:public Father 
{
public:
    virtual void Do()
	{
		cout << "Child::Do" << endl;
	}
};

class Grandchild:public Child 
{
public:
    void Do() //NOTE this is also a 
	{
		cout << "Grandchild::Do" << endl;
	}
	void Fun()
	{
		cout << "Grandchild::Fun" << endl;
	}
};

void Call(Father *p)
{
	p->Fun();
	p->Do();
}

int main()
{
	Call(new Father());// Father's Fun and Do
	Call(new Grandchild()); // Father's Fun + Grandchild's Do
	return 0;
}