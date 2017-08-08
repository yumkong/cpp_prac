// given an int array of size n, find all elems that appear more than floor(n/3) times
// should run O(n) time and O(1) space
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
        int len = nums.size();
		if(len == 0) return res;
		// there are only two such majority nums
		int num1 = nums[0], num2 = nums[0], cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < len; ++i)
		{
			if(nums[i] == num1) ++cnt1;
			else if(nums[i] == num2) ++cnt2;
			else if(cnt1 == 0) {num1 = nums[i]; ++cnt1; }
		    else if(cnt2 == 0) {num2 = nums[i]; ++cnt2; }
			else {--cnt1; --cnt2;}
		}
		cnt1 = 0;
		cnt2 = 0;
		for(int i = 0; i < len; ++i)
		{
			if(nums[i] == num1) ++cnt1;
			else if(nums[i] == num2) ++cnt2;
		}
		if(cnt1 > len / 3) res.push_back(num1);
		if(cnt2 > len / 3) res.push_back(num2);
		return res;
    }
};

int main()
{
    //vector<int> arr({1,1,1,3,3,2,3,3,3,4,5,6});
	int a[] = {1,1,1,3,3,2,3,3,3,4,5,6};
	vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    vector<int> res = solu.majorityElement(arr);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
