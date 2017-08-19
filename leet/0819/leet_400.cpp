// find the n-th digit of the infinite int sequence 1,2,3,4,5,6,7,8,9,10,11,...
//e.g.: the 11th digit is 0, which is part of the number 10
#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long bitnum = 1, base = 9;
        while(base * bitnum < (long)n)
        {
            n -= (int)bitnum * (int)base;
            ++bitnum;
            base *= 10;
        }
        // get what the number is
        int idx = n % bitnum;
        if(idx == 0) idx = bitnum;
        long num = 1;
        for(int i = 1; i < bitnum; ++i) num *= 10;
        num += (idx == bitnum) ? n / bitnum - 1 : n / bitnum;
        // get the digit
        for(int i = idx; i < bitnum; ++i) num /= 10;
        return num % 10;
    }
};

int main()
{
    Solution solu;
    cout << solu.findNthDigit(1000) << endl;
    return 0;
}
