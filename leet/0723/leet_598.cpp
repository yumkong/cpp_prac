// range addition2: given an maxtrx M of size m*n, and [[a1, b1], [a2, b2], ...]
// each time i the elements in the range [0:ai-1, 0:bi-1] is incremented by 1
// return the number of maximum integers int the matrix after performing all the operations
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        int minrow = m;
        int mincol = n;
        int len = ops.size();
        for(int i = 0; i < len; ++i)
        {
            minrow = min(minrow, ops[i][0]);
            mincol = min(mincol, ops[i][1]);
        }
        return minrow * mincol;
    }
};

int main()
{
    Solution solu;
    // 10, 10
    vector<int> a1(2, 10); 
    // 5, 5
    vector<int> a2(2, 5);
    // 3, 9
    vector<int> a3(2, 9);
    a3[0] = 3;
    vector<vector<int> > arr;
    arr.push_back(a1);
    arr.push_back(a2);
    arr.push_back(a3);
    cout << solu.maxCount(100, 100, arr) << endl;
    return 0;
}
