// climbing stairs
// it takes n (a positive int) steps to reach to the top
// each time can either climb 1 or 2 steps, how many distinct ways to climb to the top
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        // number of ways until the point [n - 1]
        int one_step_before = 2;
        // number of ways until the point [n - 2]
        int two_step_before = 1;
        // number of ways to get to the point [n]
        int all_ways = 0;
        for(int i = 2; i < n; ++i)
        {
            all_ways = one_step_before + two_step_before;
            two_step_before = one_step_before;
            one_step_before = all_ways;
        }
        return all_ways;
    }
};

int main()
{
    Solution solu;
    cout << solu.climbStairs(44) << endl;
    return 0;
}
