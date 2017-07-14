#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_int = ~(1 << 31);
        int min_int = (1 << 31);
        int len = nums.size();
        if(len == 3) return nums[0] * nums[1] * nums[2];
        // max1 > max2 > max3 > ... > min2 > min1
        int max1 = min_int, max2 = min_int, max3 = min_int, min1 = max_int, min2 = max_int;
        // one pass: O(n)
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] > max1) 
            { 
                // NOTE: reversely assign
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2) 
            {
                // NOTE: reversely assign
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3)
            {
                max3 = nums[i];
            }
            // should be independent to calcu max
            if(nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2)
            {
                min2 = nums[i];
            }
        }
        //cout << "max1 = " << max1 << endl;
        //cout << "max2 = " << max2 << endl;
        //cout << "max3 = " << max3 << endl;
        //cout << "min1 = " << min1 << endl;
        //cout << "min2 = " << min2 << endl;
        if(max1 <= 0) 
        {
            return max1 * max2 * max3;
        }
        else
        {
            if (min1 * min2 > max2 * max3) return min1 * min2 * max1;
            else return max1 * max2 * max3;
        }
    }
};

int main()
{
    int arr[] = {-4, -3, -2, 60};
    vector<int> vi(arr, arr+sizeof(arr)/sizeof(int));
    Solution solu;
    cout << solu.maximumProduct(vi) << endl;
    return 0;
}
