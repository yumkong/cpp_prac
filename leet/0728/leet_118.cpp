// generate the first numRows of Pascal's triangle
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows <= 0) return res;
        vector<int> prev(1, 1); // [1]
        for(int i = 1; i <= numRows; ++i)
        {
            vector<int> arr(i, 1);
            for(int j = 1; j < i - 1; ++j) 
            {
                arr[j] = prev[j-1] + prev[j];
            }
            res.push_back(arr);
            prev = arr;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > res = solu.generate(6);
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
