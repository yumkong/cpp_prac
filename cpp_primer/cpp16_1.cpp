#include <iostream>
using namespace std;

template <typename T>
T get_abs(T a)
{
    return (a > 0)?a:(-a);
}

int main()
{
    int a = -98;
    double b = 0.98;
    float c = -0.05;
    cout << a << " => " << get_abs(a) << endl;
    cout << b << " => " << get_abs(b) << endl;
    cout << c << " => " << get_abs(c) << endl;
    return 0;
}
