// compute the square root of x
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        int left = 1, right = ~(1 << 31); // max_int
        while(true)
        {
            int mid = left + (right - left)/2;
            // NOTE  wrtie "mid <= x/mid" instead of "mix * mid <= x" to avoid overflow
            if(mid <= x / mid) 
            {
                if((mid + 1) > x/(mid + 1)) return mid;
                else left = mid + 1;
            }
            else right = mid - 1;
        }
    }
};

int main()
{
    Solution solu;
    cout << solu.mySqrt(1) << endl;
    cout << solu.mySqrt(5834) << endl;
    return 0;
}
