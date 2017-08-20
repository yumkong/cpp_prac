// Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
// 1 <= length of the array <= 20.
// Any scores in the given array are non-negative integers and will not exceed 10,000,000.
// If the scores of both players are equal, then player 1 is still the winner.
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // maximum effective score possible for the subarray nums[i,j]
        int len = nums.size();
        vector<vector<int> > dp(len + 1, vector<int>(len, 0));
        for(int start = len; start >= 0; --start)
        {
            for(int end = start + 1; end < len; ++end)
            {
                int a = nums[start] - dp[start + 1][end];
                int b = nums[end] - dp[start][end - 1];
                dp[start][end] = max(a, b);
            }
        }
        return dp[0][len - 1] >= 0;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,5,233,7});
    // whether the 1st player (who picks the first) is the winner 
    cout << solu.PredictTheWinner(input) << endl;
    return 0;
}
