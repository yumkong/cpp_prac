// given an array of n integers, find 3 ints s.t. the sum of them is closest to a given number
// return this sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // assume >=3, here skip the check  
        int len = nums.size();
        if(len == 3) return nums[0] + nums[1] + nums[2];       
        int remain, second, last, sum2;
        int max_int = ~(1 << 31);
        int best_diff = max_int, prev_diff = max_int, diff = max_int;
	int sign = 1, prev_sign, best_sign;
        for(int first = 0; first < len - 2; ++first)
        {
            remain = target - nums[first];
            second = first + 1;
            last = len - 1;
    //        cout << "come1, first = " << nums[first] << endl;
            while(second < last)
            {
                sum2 = nums[second] + nums[last];
                if(sum2 == remain)
                {
                    diff = 0;
                    sign = 1;
                }
                else if(sum2 < remain)
                {
                    ++second;
                    diff = remain - sum2;
                    sign = 1;
                }
                else
                {  
                    --last;
                    diff = sum2 - remain;
                    sign = -1;
                }
  //              cout << "diff = " << diff << endl;
		if(diff == 0) // 1st time prev_diff = max_int
                {
                    prev_diff = diff;
                    prev_sign = sign;
                    break;
                }
                else if(diff < prev_diff) // always keep the smallest diff
                {
                    prev_diff = diff;
                    prev_sign = sign;
                }
            }
            if(prev_diff < best_diff)
            {
                best_diff = prev_diff;
                best_sign = prev_sign;
            }
            prev_diff = max_int; // this is a must!!!!!!!
//            cout << "come2, best_diff = " << best_diff << ", best_sign = " << best_sign << endl;
        }
        return target - best_sign * best_diff;
    }
};

int main()
{
    int a[] = {-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.threeSumClosest(arr, 0) << endl;
    return 0;
}
