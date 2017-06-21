// generate the n-th Fibonacci number
#include <iostream>
using namespace std;

// use long long to avoid upflow
typedef long long lint;
lint Fibo(lint n)
{
    if(n < 1) return -1;
    if(n == 1 || n == 2) return 1;
    else return Fibo(n-1) + Fibo(n-2);
}

int main()
{
    int n = 10;
    cout << "Fibonacci number of n is " << Fibo(n) << endl;
    return 0;
}
