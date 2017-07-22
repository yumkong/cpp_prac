// divide two integers without x, / and % 
// if overflow, return MAX_INT
#include <iostream>
//#include <climits> // INT_MAX
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int max_int = ~(1 << 31);
        int min_int = (1 << 31);
        if(dividend == min_int && divisor == -1) return max_int; // overflow
        if(dividend == min_int && divisor == 1) return min_int; // overflow
        if(divisor == min_int) return (dividend == min_int)? 1: 0;
        if(divisor == 0) return max_int; // overflow
        if(dividend == 0) return 0;
        int sign = 1;
        int flag = 0; // min_int occurs
        if(dividend < 0 && dividend != min_int)
        {
            sign = -1;
            dividend = -dividend;
        }
        else if(dividend == min_int)
        {
            sign = -1;
            dividend = max_int;
            flag = 1;
        }
        if(divisor < 0)
        {
            sign = sign * (-1);
            divisor = -divisor;
        }
        if(dividend < divisor) return 0;
        if(divisor == 1) return sign * dividend;
        int res = 0;
        while(dividend >= divisor)
        {
            int restmp = 1, i = 0;
            // NOTE: here if prevent the shifting << 1 from overflow
            if(divisor <= (max_int >> 1))
            {
                for(i = 1; i < 31; ++i)
                {
                    if(dividend >= (divisor << i) && (divisor << i) <= (max_int >> 1)) 
                    {
                        if(i == 0) restmp = 1;
                        else restmp = restmp * 2;
                    }
                    else break;
                } 
                dividend -= (divisor << (i-1));
                res += restmp;
            }
            else
            {
                dividend -= divisor;
                ++res;
            }
            //for debug
            //cout << "i = " << i << ", devidend = " << dividend << ", res = " << res << endl;
        }
        // to compensate the flipping of min_int to max_int
        if(dividend + flag >= divisor) ++res;
        return sign * res;
    }
};

int main()
{
    int a = 2147483647;
    int b = 1100540749;
    int d = -1090366779;
    int c = 3;
    int e = -1139973263;
    int f = -1119586052;
    Solution solu;
    cout << solu.divide(e, f) << ", answer = " << e/f << endl;
    cout << solu.divide(a, c) << ", answer = " << a / c << endl;
    cout << solu.divide(b, d) << ", answer = " << b / d << endl;;
    return 0;
}
