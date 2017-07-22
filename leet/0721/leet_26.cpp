// given an sorted array, remove the duplicated in place
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        if(len == 2) return (nums[0] < nums[1])? 2:1;
        int cnt = 1;
        int first = 0, mid = 1, last = 1;
        while(last < len)
        {
            if(nums[first] < nums[last])
            {
                if(mid < last) swap(nums[mid], nums[last]);
                // whether swap or not, must do this
                ++first;
                ++mid;
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

