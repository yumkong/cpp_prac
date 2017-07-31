// given an index k, return kth row of the Pascal's triangle
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1); // k = 0: [1], 1:[1 1], 2:[1 2 1]
        if(rowIndex <= 1) return res;
        long tmp = 1;
        for(int i = 1; i <= rowIndex/2; ++i)
        {
            // here use long to avoid multiplication overflow
            res[i] = (int)(tmp * (rowIndex + 1 - i) / i);
            res[rowIndex - i] = res[i]; 
            tmp = res[i];
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> res = solu.getRow(30);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
