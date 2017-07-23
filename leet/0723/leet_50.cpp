//implement pow(x, n)
#include <iostream>
#include <cmath>  // for debug
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0) return 0.0;
        if(n == 0) return 1.0;
        if(n == 1) return x;
        int sign = 1;
        double res = 1;
        if(n < 0)
        {
            x = 1.0 / x;
            n = -n;
        }
        return helper(x, n);
    }
    // must use recursion to avoid time limit
    double helper(double x, int n)
    {
        //cout << "come1" << endl;
        if(n == 0) return 1.0;
        if(n == 1) return x;
        return (n % 2 == 0)? helper(x * x, n / 2) : helper(x * x, n / 2) * x; 
    }
};

int main()
{
    Solution solu;
    cout << solu.myPow(1.2, 3) << endl;
    cout << "0.00001 ^ 2147483647 = " << pow(0.00001, 2147483647) << endl;
    cout << "10 ^ 2147483647 = " << pow(10, 2147483647) << endl;
    return 0;
}

