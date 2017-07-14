//a toy program to study constructors
#include <iostream>
#include <vector>
using namespace std;

struct Exmpl
{
    // default constructor
    Exmpl()
    { cout << "Exmpl()" << endl; }
    // copy constructor
    Exmpl(const Exmpl&)
    { cout << "Exmpl(const Exmpl&)" << endl; }
    //assignment operator
    Exmpl& operator=(const Exmpl& rhs)
    {
        cout << "operator = (const Exmpl&)" << endl;
        return *this;
    }
    ~Exmpl()
    { cout << "~Exmpl()" << endl;}
};

void func1(Exmpl obj)
{}

void func2(Exmpl& obj)
{}

Exmpl func3()
{
    Exmpl obj;
    return obj;
}

int main()
{
    Exmpl eobj;  // Exmpl()
    func1(eobj);  // Exmpl(const Exmpl&) + ~Exmpl()
    func2(eobj);  // (when param is reference, no need to call copy constructor to pass argum)
    eobj = func3();  // Exmpl() + Exmpl(const Exmpl&) + ~Exmpl + operator=... + ~Exmpl (destroy the returned tmp obj)
    Exmpl *p = new Exmpl;  // Exmpl()
    // 0629: first create a tmp obj, then use it to copy constructing three objs, then delete the temp obj
    vector<Exmpl> evec(3);  // Exmpl()  Exmpl(const Exmple&)  Exmpl(const Exmpl&) Exmpl(const Exmpl&)  ~Exmpl()
    delete p;   // ~Exmpl()
    // 0629: delete eobj and evec(3)
    return 0;  // ~Exmpl() x 4
}
