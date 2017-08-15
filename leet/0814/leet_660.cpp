// start from integer 1, remove any integer containing 9. Now given a positive int n, 
// return the n-th integer after removing
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int newInteger(int n) {
        // [0] => how many 9 from 1-1, [1] => how many 9 from 1-10, ...
        vector<int> numTbl(10, 0);
        for(int i = 1; i < 10; ++i) numTbl[i] = numTbl[i-1] * 9 + pow(10, i-1);
        int diff = 0, miss = 0;
        while(1)
        {
            miss = getNineNum(n + diff, numTbl);
            if(diff != miss) diff = miss;
            else break;
        }
        int res = n + diff;
        return (res % 10 == 9) ? (res - 1): res;
    }
    int getNineNum(int n, vector<int>& numTbl)
    {
        int tmp = n, nineCnt = 0, nbit = 0;
        while(tmp > 0)
        {
            nineCnt += (tmp % 10) * numTbl[nbit];
            // % is prior to +
            if(tmp % 10 == 9) nineCnt += (n % (int)pow(10, nbit) + 1);
            ++nbit;
            tmp /= 10;
        }
        return nineCnt;
    }
};

int main()
{
    Solution solu;
    cout << solu.newInteger(10000000) << endl;
    //cout << solu.getNineNum(20731371) << endl;
    //cout << solu.getNineNum(19731371) << endl;
    return 0;
}
