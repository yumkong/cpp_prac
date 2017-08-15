// fraction addition and subtraction
// using lowest common multiple(LCM) and greatest common divisor (GCD)
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        // give the first fraction a sign
        if(expression[0] != '-') expression = "+" + expression;
        int len = expression.size();
        //n: final nominator, d: final denominator, p: start position of a fraction
        // p1: postion of '/', p2: end position of a fraction
        int n = 0, d = 1, p = 0, p1 = 0, p2 = 0;
        while(p < len)
        {
            for(p1 = p + 1; expression[p1] != '/'; ++p1);
            for(p2 = p1 + 1; p2 < len && expression[p2] != '+' && expression[p2] != '-'; ++p2);
            //local nominator and denom
            //cout << "p1 = " << p1 << ", p2 = " << p2 << endl; 
            int nn = stoi(expression.substr(p+1, p1 - p - 1));
            int dd = stoi(expression.substr(p1 + 1, p2 - p1-1));

            int gcd = GCD(d, dd); // first time = GCD(dd,1) = 1
            // update final nomi and denom: n/d = n/d (+/-) nn/dd
            // n/(d/gcd) (+/-) nn/(dd/gcd) = n * dd/gcd (+/-) nn * d/gcd / 
            n = n * dd / gcd + (expression[p] == '-'? -1: 1) * nn * d/ gcd;
            d *= dd/gcd;
            //cout << "n = " << n << ", d = " << d << endl;
            p = p2; // update the fraction's starting pos
        }
        // final division
        int gcd = GCD(abs(n), d);
        return to_string(n / gcd) + "/" + to_string(d / gcd);
    }
    int GCD(int a, int b)
    {
        while(b != 0)
        {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};

int main()
{
    Solution solu;
    cout << solu.fractionAddition("1/3-1/2") << endl;
    return 0;
}
