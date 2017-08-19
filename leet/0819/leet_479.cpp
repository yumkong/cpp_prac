// find the largest palindrome made from the product of two n-digit numbers
// NOTE: since the result could be very large, should return the largest palindrome mod 1337
#include <iostream>
#include <cmath>
#include <string> //stoi,stol(to long int) to_string
#include <algorithm> //reverse
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int upperbnd = pow(10, n) - 1, lowerbnd = upperbnd / 10;
        long maxNum = (long)upperbnd * (long)upperbnd;
        // the first half of the maximum assumed palindrome
        int firsthalf = (int)(maxNum / (long)pow(10, n));
        bool found = false;
        long palin = 0;
        while(!found)
        {
            // create maximum assumed palindrome
            palin = createPalin(firsthalf);
            for(long i = upperbnd; upperbnd > lowerbnd; --i)
            {
                if(palin / i > maxNum || i * i < palin) break;
                if(palin % i == 0) {found = true; break;}
            }
            --firsthalf;
        }
        return (int)(palin % 1337);
    }
    long createPalin(long num)
    {
        string tmp = to_string(num);
        string tmp2 = tmp;
        reverse(tmp.begin(), tmp.end());
        return stol(tmp2 + tmp);
    }
};

int main()
{
    Solution solu;
    cout << solu.largestPalindrome(2) << endl; // 9009 % 1337 = 987
    return 0;
}
