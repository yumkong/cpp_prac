// given a 2D binary matrix with 0's and 1's, find the largest rectangle containing only 1's and return its area

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//maintain a row length of Integer array H recorded its height of '1's, and scan and update row by row to find out the largest rectangle of each row.
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        if(col == 0) return 0;
        // record how many 1's in each column
        // NOTE: here add a border term at col-th idx 
        vector<int> hist(col + 1, 0);
        int res = 0;
        for(int r = 0; r < row; ++r)
        {
            stack<int> st;
            for(int c = 0; c < col + 1; ++c)
            {
                if(c < col)
                {
                    // 
                    if(matrix[r][c] == '1') hist[c] += 1;
                    else hist[c] = 0;
                }
                // stack keep the increasing hist bar's column index
                if(st.empty() || hist[st.top()] <= hist[c]) st.push(c);
                else
                {
                    // when decreasing, compute the area of the high bar's in the middle
                    // until the bars recover's increasing (more precisely non-decreasing) order
                    while(!st.empty() && hrecord[c] < hrecord[st.top()])
                    {
                        int tmp = st.top(); st.pop();
                        int area = hist[tmp] * (st.empty()? c : (c - st.top() - 1));
                        if(area > res) res = area;
                    }
                    st.push(c);
                } 
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<char> > input;
    input.push_back(vector<char>({'1', '0', '1', '0', '0'}));
    input.push_back(vector<char>({'1', '0', '1', '1', '1'}));
    input.push_back(vector<char>({'1', '1', '1', '1', '1'}));
    input.push_back(vector<char>({'1', '0', '0', '1', '0'}));
    cout << solu.maximalRectangle(input) << endl;
    return 0;
}
