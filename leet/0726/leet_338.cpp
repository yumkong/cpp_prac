// given a non-negative integer num, for every numbers i in range 0<= i <= num, calculate the number of 1's in their binary representation, return them as an array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; ++i) res[i] = res[i & (i - 1)] + 1;
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> res = solu.countBits(5);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
