// minmax problem
// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
//What if we change the game so that players cannot re-use integers?
//For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
// assume: maxChoosableInteger <= 20 and desiredTotal <= 300
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
    }
};

int main()
{
    Solution solu;
    cout << solu.canIWin(10, 11) << endl;
    return 0;
}
