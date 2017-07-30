#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        sort(nums.begin(), nums.end());
        map<int, int> m_cnt;
        int len = nums.size();
        
        int cnt = 0;
        if(k > 0)
        {
            //cout << "here 1" << endl;
            for(int i = 0; i < len; ++i)
            {
                ++m_cnt[nums[i]];
                if(m_cnt[nums[i]] == 1 && m_cnt.count(nums[i] - k) > 0) ++cnt;
                //++m_cnt[nums[i]];
            }
        }
        else
        {
            //cout << "here 2" << endl;
            for(int i = 0; i < len; ++i)
            {
                // put forward or backward, this make a sense
                ++m_cnt[nums[i]];
                if(m_cnt.count(nums[i] - k) > 0 && m_cnt[nums[i]] == 2) ++cnt;
                //++m_cnt[nums[i]];
            }

        }
        return cnt;
    }
};

int main()
{
    int a[] = {1,1,1,1,1}; // 0
    int a2[] = {3,1,4,1,5}; // 2
    int a3[] = {1,2,3,4,5}; // 1
    int a4[] = {1,3,1,5,4}; // 0
    int a5[] = {1,1,1,2,2}; // 1
    vector<int> arr(a, a+ sizeof(a)/sizeof(a[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    vector<int> arr4(a4, a4 + sizeof(a4)/sizeof(a4[0]));
    vector<int> arr5(a5, a5 + sizeof(a5)/sizeof(a5[0]));
    Solution solu;
    cout << solu.findPairs(arr, 0) << endl;
    cout << solu.findPairs(arr2, 2) << endl;
    cout << solu.findPairs(arr3, 1) << endl;
    cout << solu.findPairs(arr4, 0) << endl;
    cout << solu.findPairs(arr5, 1) << endl;
    return 0;
}
