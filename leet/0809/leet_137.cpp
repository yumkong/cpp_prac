// single number II: given an int array, every element appears three  times except for one,
// which appears exactly once. Find that single one number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		// method 1, time O(32n), easy to understand and extend
		/*
        int res = 0, len = nums.size();
		for(int i = 0; i < 32; ++i)
		{
			int sum = 0;
			for(int j = 0; j < len; ++j)
			{
				sum += ((nums[j] >> i) & 1); 
			}
			if(sum % 3 != 0) res |= (1 << i); 
		}
		return res;*/
		// method 2: just for this question (hard to understand, need to rethink later)
		int ones = 0, twos = 0;
		for(int i = 0; i < nums.size(); ++i)
		{
			ones = ones ^ nums[i] & ~twos; // at 1st time, ones has but twos will be 0
			// at 2nd time ones is zero s.t. twos can has, the 3rd, ones will not have either
			// because of being masked by twos
			twos = twos ^ nums[i] & ~ones; 
		}
		return ones;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,1,1,2,2,2,3,4,4,4,5,5,5});
    cout << solu.singleNumber(input) << endl;
    return 0;
}
