// Category: reservoir sampling
// given an array of ints with possible duplicates, randomly output the index of a given target number (assume that it must exist in the array)
// NOTE: The array size can be very large. Solution that uses too much extra space will not pass the judge.
// eg:
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);
// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);
#include <iostream>
#include <vector> 
#include <cstdint> // rand()
using namespace std;

class Solution {
private:
    vector<int> arr;
public:
    Solution(vector<int> nums) {
        arr = nums;
    }
    
    int pick(int target) {
        int n = 0, res = -1;
        for(int i = 0; i < arr.size(); ++i)
        {
            if(arr[i] != target) continue;
            if(n == 0) {res = i; ++n; } // first time occurence
            else
            {
                ++n;
                // replace the previous index with prob 1 / (n + 1)
                if(rand() % n == 0) {res = i;}
            }
        }
        return res;
    }
};

int main()
{
    vector<int> input({1,2,2,3,3,3});
    Solution obj(input);
    for(int i = 0; i < 10; ++i) cout << obj.pick(3) << endl;
    return 0;
}
