//in close relation with leet_85.cpp
// given n non-negative ints representing a histogram's bar hight, the width of each bar is 1,
// find the area of largest rectangle in the histogram
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 1) return heights[0];
        int res = 0;
        stack<int> st;
        // add a border term
        heights.push_back(0);
        for(int i = 0; i < len + 1; ++i)
        {
            // stack keep the bar index where these bars are in ascending order
            if(st.empty() || heights[st.top()] <= heights[i]) st.push(i);
            else
            {
                // if the bar height begin to descend, pop out until ascending status reappear
                // when popping out, compute the area at the same time
                while(!st.empty() && heights[i] < heights[st.top()])
                {
                    int tmp = st.top(); st.pop();
                    int area = heights[tmp] * (st.empty()? i : (i - st.top() - 1));
                    if(area > res) res = area;
                }
                st.push(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> heights({2,1,2,3,5,6});
    cout << solu.largestRectangleArea(heights) << endl;
    return 0;
}
