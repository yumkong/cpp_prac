//given an array and a value, remove all instances of that value in place and return the new length
// eg: nums = [3,2,2,3], val = 3 ==> [2,2], length = 2
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return (nums[0] == val)?0:1;
        // bidirection pointer
        int left = 0, right = len - 1;
        while(left < right)
        {
            if(nums[left] != val) ++left;
            if(nums[right] == val) --right;
            // check if it's time for swapping
            if(left < right && nums[left] == val && nums[right] != val)
            {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        if(left > right) return left;
        if(left == right) return (nums[left] == val)? left : (left + 1);
    }
    void swap(int& x, int& y)
    {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
};

int main()
{
    int a[] = {4,5};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << "length = " << solu.removeElement(arr, 5) << endl;
    for(int i = 0; i < arr.size(); ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
