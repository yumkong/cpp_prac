// category: brainteaser
// given n bulbs which are initially off, first turn on all the bulbs. Then turn off every second bulb.
// on the 3rd round, toggle every third bulb, for the ith round, toggle every ith bulb, for the nth round only toggle the nth bulb
// find how many bulbs are on after n rounds
// USE property: The number of one number's factor is odd if and only if it is a perfect square (aka num = x ^ 2)
#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int res = 0;
        for(int i = 1; i * i <= n; ++i) ++res;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.bulbSwitch(3) << endl;
    return 0;
}
