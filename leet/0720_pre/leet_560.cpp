#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> sum_cnt;
        ++sum_cnt[0]; // 1: 0 is a natural sum
        int sum = 0, cnt = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            //check if sum-k exist: map.count return 1 of exist, 0 otherwise
            if(sum_cnt.count(sum - k) > 0)
            {
                cnt += sum_cnt.at(sum - k);
            }
            ++sum_cnt[sum];
        }
        return cnt;
    }
};

int main()
{
	int a[] = {1,1,1};
	vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
	Solution solu;
	cout << solu.subarraySum(arr, 2) << endl;
	return 0;
}