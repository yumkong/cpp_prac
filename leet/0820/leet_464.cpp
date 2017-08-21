// minmax problem
// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
//What if we change the game so that players cannot re-use integers?
//For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
// assume: maxChoosableInteger <= 20 and desiredTotal <= 300
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    vector<map<int, bool> > vm;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int mcI = maxChoosableInteger, dT = desiredTotal;
        // corner case, player 1 is sure to win or lose
        if(mcI >= dT) return true;
        if(mcI + 1 >= dT) return false;
        map<int, bool> mp;
        vm.assign(301, mp);
        // if all available ints are used but still not reach desired total, return false
        if(mcI * (mcI + 1) / 2 < dT) return false;
        // all mcI bits are set to 1
        return helper((1 << (mcI + 1)) - 1, dT, mcI);
    }
    bool helper(int indicate, int total, int mcI)
    {
        if(vm[total].count(indicate) > 0) return vm[total][indicate];
        for(int i = mcI; i >= 1; --i)
        {
            int p = (1 << i);
            // means i has not been picked yet
            if((p & indicate) == p)
            {   // use p
                int next = (indicate ^ p);
                int totalNext = total - i;
                if(totalNext <= 0) return true;
                bool x;
                if(vm[totalNext].count(next) > 0) x = vm[totalNext][next];
                else x = helper(next, totalNext, mcI);
                if(!x) // x = false
                {
                    vm[total][indicate] = true;
                    return true;
                }
            }
        }
        vm[total][indicate] = false;
        return false;
    }
};

int main()
{
    Solution solu;
    cout << solu.canIWin(10, 11) << endl;
    return 0;
}
