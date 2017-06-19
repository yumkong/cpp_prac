// hanoi tower only has three needles x, y and z
// any time and needle: big bottom and small top
#include <iostream>
using namespace std;

// x -> z through y
void move(int n, char x, char y, char z)
{
    if(n == 1)
    {
        cout << x << " => " << z << endl;
    }
    else
    {
        move(n - 1, x, z, y);
        cout << x << " => " << z << endl;
        move(n - 1, y, x, z);
    }
}

int main()
{
    int n;
    cout << "Input disk number: " << endl;
    cin >> n;
    if(n >= 1)
    {
        cout << "The steps to moving " << n << " diskes:" << endl;
        move(n, 'A', 'B', 'C');
    }
    else
    {
        cout << "Invalid int number." << endl;
    }
    return 0;
}
