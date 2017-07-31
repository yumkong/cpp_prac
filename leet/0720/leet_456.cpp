// given a sequence of n ints: a1, a2, ... an, find whether or not having 132 pattern:
// i < j < k and  ai < ak < aj
// principle: at any time in the stack, non-overlapping Pairs are formed in descending order they  their min value
#include <iostream>
#include <stack>
#include <vector>
#include <utility> // pair
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return false;
        if(len == 3) return (nums[0] < nums[2]) && (nums[2] < nums[1]);
        // s1 for storing ai (min), s2 for storing aj (max)
        typedef pair<int, int> pii;
        stack< pii > s1;// <min1, max1>, <min2, max2>, ...where min1 > min2 > ...
        for(int i = 0; i < len; ++i)
        {
            int tmp = nums[i];
            if(s1.empty() || s1.top().first > tmp)
            {
                s1.push(make_pair(tmp, tmp));
            }
            else if(nums[i] > s1.top().first)
            {
                pii stacktop = s1.top();
                s1.pop();
                if(tmp < stacktop.second) return true;
                else
                {
                    stacktop.second = tmp;
                    while(!s1.empty() && tmp >= s1.top().second) 
                    {   // pop it (delete it) because stacktop can totally cover it
                        s1.pop();
                    } 
                    // after the above while, we know: tmp < s1.top().second
                    if(!s1.empty() && s1.top().first < tmp) return true;
                    s1.push(stacktop);
                }
            }
        }
        return false;
    }
};

int main()
{
    int a[] = {3,1,4,2};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.find132pattern(arr) << endl;
    return 0;
}
