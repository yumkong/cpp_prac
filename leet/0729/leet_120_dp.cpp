// dp solution of leet_120
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // return a reference to the last element in the vector
        vector<int> tmpvec = triangle.back();
        int len = triangle.size();
        for(int i = len - 2; i >= 0; --i)
        {
            int len1 = triangle[i].size();
            for(int j = 0; j < len1; ++j)
            {
                tmpvec[j] = min(tmpvec[j], tmpvec[j+1]) + triangle[i][j];
            }
        }
        return tmpvec[0];
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > input;
    // use c++11 for convenience
    input.push_back(vector<int>({2}));
    input.push_back(vector<int>({3,4}));
    input.push_back(vector<int>({6,5,7}));
    input.push_back(vector<int>({4,1,8,3}));
    cout << solu.minimumTotal(input) << endl;
    return 0;
}
