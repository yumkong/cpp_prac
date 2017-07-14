//12.38, 12.39, 12.40, 12.41
#include <iostream>
using namespace std;

class Foo
{
private:
    int value;
public:
    Foo(int x):value(x) {}
    int get() { return value; };
};

class Bar
{
private:
    static int ival;
    static Foo fval;
public:
    static int callsFooVal;
public:
    Foo FooVal()
    {
        ++callsFooVal;
        return fval;
    }
};
int Bar::ival = 20;
Foo Bar::fval(0);
int Bar::callsFooVal = 0;

int main()
{
    Bar bar1;
    Foo fo = bar1.FooVal();
    cout << fo.get() << " " << bar1.callsFooVal << endl;
    return 0;
}
