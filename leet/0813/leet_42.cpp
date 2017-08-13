// trapping rain water
// given n non-negative ints representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 2) return 0;
        stack<int> st;
        int curmax = 0;
        int res = 0;
        for(int i = 0; i < len; ++i)
        {
            if(curmax <= height[i] && height[i] > 0)
            {
                if(st.size() >= 2)
                {
                    while(!st.empty())
                    { 
                        res += (curmax - st.top()); 
                        st.pop();
                    } 
                }
                else { if(!st.empty()) st.pop(); }
                curmax = height[i];
                st.push(height[i]);
            }
            else if(curmax > height[i]) // curmax > height[i]
            { st.push(height[i]); }
        }
        //dealing with the last trap
        if(!st.empty())
        {
            stack<int> st2;
            int curmax2 = 0;
            while(!st.empty())
            {
                int tmp = st.top(); st.pop();
                if(curmax2 <= tmp && tmp > 0)
                {
                    if(st2.size() >= 2)
                    {
                        while(!st2.empty())
                        { 
                            res += (curmax2 - st2.top()); 
                            st2.pop(); 
                        }
                    }
                    else { if(!st2.empty()) st2.pop(); }
                    curmax2 = tmp;
                    st2.push(tmp);
                }
                else if(curmax2 > tmp) // curmax > height[i]
                { st2.push(tmp); }
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> height({0,1,0,2,1,0,1,3,2,1,2,1});
    cout << solu.trap(height) << endl;
    return 0;
}
