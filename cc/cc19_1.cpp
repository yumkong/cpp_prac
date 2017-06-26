// swap two numbers in place without temporary variables
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    b = a - b;
    a = a - b; //== a - (a-b) = b
    b = b + a; // a - b + b = a
}

int main()
{
    int x = 12, y = 68;
    cout << "original x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "after swap x = " << x << ", y = " << y << endl;
    return 0;
}
