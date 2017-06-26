// a toy program to show C++'s hiding name phenonmenon
#include <iostream>
using namespace std;

class FirstClass
{
public:
    virtual void MethodA(int)
    {
        cout << "FirstClass::MethodA(int)" << endl;
    }
    virtual void MethodA(int, int)
    {
        cout << "FirstClass::MethodA(int, int)" << endl;
    }
};

class SecondClass: public FirstClass
{
public:
    void MethodA(int)
    {
        cout << "SecondClass::MethodA(int)" << endl;
    }
};

int main()
{
    SecondClass a;
    a.MethodA(1);
    //a.MethodA(1, 2);
    return 0;
}
