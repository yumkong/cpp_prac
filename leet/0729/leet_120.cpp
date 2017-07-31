// given a triangle find the minimum path sum from top to bottom
// a top node_level1 [i] can only move to adjacent numbers on the row below node_level2[i], [i+1]
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = ~(1<<31); // max_int
        int trisiz = triangle.size();
        for(int i = 1; i < trisiz; ++i)
        {
            int len = triangle[i].size();
            triangle[i][0] += triangle[i-1][0];
            triangle[i][len-1] += triangle[i-1][len-2];
            for(int j = 1; j < len - 1; ++j)
            {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        for(int i = 0; i < triangle[trisiz-1].size(); ++i)
        {
            if(triangle[trisiz-1][i] < sum) sum = triangle[trisiz-1][i];
        }
        return sum;
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
