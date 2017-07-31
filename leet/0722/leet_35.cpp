// given a sorted array and target value, return the index if the targe is found
// if not found, return the position the targe value should be inserted
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //using binary search
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return (target <= nums[0])? 0 : 1;
        int start = 0, end = len - 1, mid;
        while(start < end)
        {
            mid = (start + end) / 2;
            if(target < nums[mid]) 
            {
                if(mid < end) end = mid;
                else break;
            }
            else if(target > nums[mid]) 
            {
                if(mid > start) start = mid;
                else break;
            }
            else return mid;
        }
        int res;
        //when come here, start+1 == end
        if(target < nums[start])  res = start;
        else if(target > nums[end]) res = end + 1;
        else res = end; //in between start and end
        return res; 
    }
};

int main()
{
    int a[] = {1,5,6};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.searchInsert(arr, 8) << endl;
    return 0;
}
