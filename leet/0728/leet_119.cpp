// given an index k, return kth row of the Pascal's triangle
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex, 1);
        if(rowIndex <= 2) return res;
        int tmp = 1;
        for(int i = 1; i < (rowIndex + 1)/2; ++i)
        {
            res[i] = tmp * (rowIndex + 1 - i) / i;
            tmp = res[i];
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> res = solu.getRow(7);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
