// given an sorted array, remove the duplicated in place
// NOTE: duplicate are allowed at most twice
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int first = 0, mid = 1, last = 1, cnt = 0;
        while(last < len)
        {
            if(nums[first] < nums[last])
            {
                // mid keep the idx till which each element has at most twice occurence
                if(mid < last) swap(nums[mid], nums[last]);
                // whether swap or not, must do this
                ++first;
                ++mid;
                cnt = 0;
            }
            else if(nums[first] == nums[last])
            {
                ++cnt;
                if(cnt <= 1) // only has one duplicates
                {
                     if(mid < last) swap(nums[mid], nums[last]);
                     // whether swap or not, must do this
                     ++first;
                     ++mid;
                }
            }
            ++last;
        }
        return first + 1;
    }
    void swap(int &a1, int &a2)
    {
        int tmp;
        tmp = a1;
        a1 = a2;
        a2 = tmp;
    }
};

int main()
{
    int a[] = {1,1,1,2,3,3,3,5,5,78,79,80,80,80,80};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.removeDuplicates(arr) << endl;
    for(int i = 0; i < arr.size(); ++i)  cout << arr[i] << endl;
    return 0;
}

