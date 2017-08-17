// A perfect square is a number that can be expressed as the product of two equal integers
// check if a given int is a perfect square
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        // method 1: using the rule: any square == 1 + 3 + 5 + 7 + 9 ...
        /*int i = 1;
        while(num > 0)
        {
            num -= i;
            i += 2;
        }
        return num == 0; */
        // method 2: using binary search
        /*if(num == 0) return true;
        int low = 1, high = num;
        while(low <= high)
        {
            // use long to avoid overflow when mid * mid
            long mid = (low + high) >> 1;
            if(mid * mid == num) return true;
            else if(mid * mid < num) low = (int)mid + 1;
            else high = (int)mid - 1;
        }
        return false;*/
        // using Newton's method: while(x_k * x_k != n) x_k+1 = 1/2 (x_k + n / x_k)
        long x = num;
        while(x * x > num)
        {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPerfectSquare(17) << endl;
    return 0;
}
