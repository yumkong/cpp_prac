// reverse an integer: e.g., -123 => -321
#include <iostream>
//#include <cstdlib> // itoa, atoi
//#include <string>
//#include <algorithm> // reverse
using namespace std;
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows
class Solution {
public:
    int reverse(int x) {
		int max_int = ~(1 << 31);
		int min_int = (1 << 31);
		/* char cs[12]; // max length of a int32 is 11 bits + 1 null bit
		itoa(x, cs, 10); //last 10 means converting to decimal
		string s(cs);
		itoa(max_int, cs, 10); //last 10 means converting to decimal
		string s_max(cs);
		itoa(min_int, cs, 10); //last 10 means converting to decimal
		string s_min(cs);
		int sign = 1;
		if(s.at(0) == '-')
		{
			sign = -1;
			s.erase(0, 1); //delete first element
		}
		std::reverse(s.begin(), s.end());
		if(s.size() >= 10)
		{
			if(sign > 0 && s > s_max) return 0;
			if(sign < 0 && s > s_min) return 0;
		}
		if(sign < 0) s.insert(0, 1, '-');//insert at the first position with 1 char '-'
		return atoi(s.c_str()); */
			
        int sign = (x>=0) ? 1 : -1;
        int xabs = x * sign;
		 
        int res = 0;
	    //do not need to check the final last digit, it equal to the first digit of input //interger(<=2) should always less than 7 or 8  
        while(xabs > 0)
        {
			// NOTE: if-clause should be put ahead
			// if only having 9 digits, if comparing is executed for 8 times
			if (res > max_int/10 || res < min_int/10)
			{
				return 0;
            }
            res = res * 10 + xabs % 10;
            xabs /= 10;
        }
        return sign * res;
    }
	
};

int main()
{
    Solution solu;
	cout << solu.reverse(1534236469) << endl;
	cout << solu.reverse(-13456) << endl;
	cout << solu.reverse(-534236469) << endl;
    return 0;
}
