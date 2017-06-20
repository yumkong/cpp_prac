#include <iostream>
using namespace std;

template <typename T>
T get_max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 93, b = 89;
    cout << a << " and " << b << " => " << get_max(a, b) << endl;
    double c = -54.5, d = -54.435;
    cout << c << " and " << d << " => " << get_max(c, d) << endl;
}
