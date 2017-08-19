// super washing machines, given n super washing machines on a line, each has some dresses or empty, for each move, can choose any m (1<= m <= n) washing machines, and pass one dress of each washing machine to one of its adjcent washing machines at the same time
// find the minimum number of moves to make all machines have the same number of dresses, if not possible, return -1
// NOTE: n = [1, 10000]
// the range of dresses number in a super machine is [0, 1e5]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size(), total = 0, avg = 0, res = 0;
        for(int i = 0; i < len; ++i) total += machines[i];
        if(total == 0) return 0; // no need to move
        if(total % len != 0) return -1;
        avg = total / len;
        vector<int> move(len, 0);
        for(int i = 0; i < len - 1; ++i)
        {
            if(machines[i] > avg)
            {
                // how many move outs from ith place to make machines[i] being avg
                move[i] += machines[i] - avg;
                // how many dresses given to the next machine
                machines[i + 1] += machines[i] - avg;
                // after all these moves the current machine is avg
                machines[i] = avg;
                // update max move
                res = max(res, move[i]);
            }
            else
            {
                // how many moves needed from the next machine to make machines[i] avg
                move[i + 1] = avg - machines[i];
                // how many left to [i+1]th machines after the above move
                machines[i + 1] -= avg - machines[i];
                // after all these moves the current machine is avg
                machines[i] = avg;
                // update max move
                res = max(res, move[i + 1]);
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,0,5}); // 3
    cout << solu.findMinMoves(input) << endl;
    return 0;
}
