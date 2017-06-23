#include <iostream>
using namespace std;

//max int
const int INF = ~(1 << 31);

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//excellent
int flipsign(int a)
{
    // if negative, incre elem is 1, otherwise -1
    int d = a < 0 ? 1 : -1;
    // opposite of a
    int opa = 0;
    while(a != 0)
    {
        a += d; // make a closing to zero
        opa += d; // make opa increase towards opposite position
    }
    return opa;
}

int abs(int a)
{
    if(a < 0) a = flipsign(a);
    return a;
}

// whether two oprands have opposite signs
bool opsign(int a, int b)
{
    return (a > 0 && b < 0) || (a < 0 && b > 0);
}

int minuss(int a, int b)
{
    return a + flipsign(b);
}

int times(int a, int b)
{
    int aa = abs(a), bb = abs(b);
    int res = 0;
    if(aa < bb) swap(aa, bb); // make left bigger to reduce addition times
    for(int i = 0; i < bb; ++i) res += aa;
    if(opsign(a, b)) res = flipsign(res);
    return res; 
}

int divide(int a, int b)
{   
    //*** 0623: later, change it to throw an error 
    if(b == 0) return INF;
    int aa = abs(a), bb = abs(b);
    int res = 0;
    // NOTE this is correct for both 7/3 = 2 and -7/3 = -2  => the results are both rounded towards 0
    for(; aa >= bb; ++res) aa = minuss(aa, bb);
    if(opsign(a, b)) res = flipsign(res);
    return res;
}

int main()
{
    int a[] = {8, 0, -8, -5, 9};
    int b[] = {3, 5, 3, 0, -3};
    for(int i = 0; i < 5; ++i)
    {
        cout << times(a[i], b[i]) << " " << minuss(a[i], b[i]) << " " << divide(a[i], b[i]) << endl;
    }
    return 0;
}
