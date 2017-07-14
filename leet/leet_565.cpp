#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        map<int, int> mcnt;
        int max_cnt = 0;
        for(int i = 0; i < len; ++i)
        {
            int idx = i, tmp_cnt = 0;
            ++mcnt[idx];
            while(mcnt[idx] == 1)
            {
                ++tmp_cnt;
                idx = nums[idx];
                ++mcnt[idx];
            }
            if(mcnt[idx] > 1)
            {
                --mcnt[idx];
                if(tmp_cnt > 0 && max_cnt < tmp_cnt) 
                {
                    max_cnt = tmp_cnt;
                    tmp_cnt = 0;
                }
            }
        }
        return max_cnt;
    }
};

int main()
{
    int a[] = {5,4,0,3,1,6,2};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.arrayNesting(arr) << endl;
    return 0;
}
