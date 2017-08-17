// find the n-th ugly number
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note 1 is typically treated as an ugly number, and n <= 1690
// inspired by discussion, using DP
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n, 1);
        for(int i = 1; i < n; ++i)
        {
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
            // if k[i] == 6, both t2 and t3 ++
            if(k[i] == k[t2] * 2) ++t2;
            if(k[i] == k[t3] * 3) ++t3;
            if(k[i] == k[t5] * 5) ++t5;
        }
        return k[n - 1];
    }
};

int main()
{
    Solution solu; 
    cout << solu.nthUglyNumber(10) << endl;
    return 0;
}
