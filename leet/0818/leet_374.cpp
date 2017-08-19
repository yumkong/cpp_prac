// pick a number from 1 to n, guess which number has been picked
// Solu: a standard binary search problem
#include <iostream>
using namespace std;

#define NUMBER 6
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
    if(num < NUMBER) return -1;
    else if(num > NUMBER) return 1;
    else return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        long mid = 0;
        while(left <= right)
        {
            mid = ((long)left + (long)right) >> 1;
            int gu = guess(mid);
            if(gu < 0) left = mid + 1;
            else if(gu > 0) right = mid - 1;
            else break;
        }
        return (int)mid;
    }
};

int main()
{
    Solution solu;
    cout << solu.guessNumber(10) << endl;
    return 0;
}
