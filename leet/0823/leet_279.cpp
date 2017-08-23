// given a positive integer n, find the least number of perfect square numbers (1,4,9, ...) which sums to n
#include <iostream>
#include <vector>
#include <climits> // INT_MAX
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // static dynamic programming
        if(n <= 0) return 0;
        // the least number of perfect square numbers which sum to i
        static vector<int> cntPS({0});
        // while not reaching n, incrementally calculate the next result
        while(cntPS.size() <= n)
        {
            int m = cntPS.size();
            int cntSqr = INT_MAX;
            for(int i = 1; i * i <= m; ++i)
            {
                cntSqr = min(cntSqr, cntPS[m - i*i] + 1);
            }
            cntPS.push_back(cntSqr);
        }
        return cntPS[n];
    }
};

int main()
{
    Solution solu;
    cout << solu.numSquares(17) << endl;
    return 0;
}
