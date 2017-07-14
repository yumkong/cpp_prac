#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		//k is abs_diff, should be larger than 0
        if(k < 0) return 0;
        sort(nums.begin(), nums.end());
        map<int, int> m_cnt;
        int len = nums.size();
        
        int cnt = 0;
        for(int i = 0; i < len; ++i)
        {
            if(m_cnt.count(nums[i] - k) > 0) ++cnt;
            ++m_cnt[nums[i]];
        }
        return cnt;
    }
};

int main()
{
	int a1[] = {3,1,4,1,5}; //k=2
	int a2[] = {1,2,3,4,5}; //k = 1
	int a3[] = {1,3,1,5,4}; //k = 0
	int a4[] = {1,1,1,1,1}; //k = 0
	vector<int> arr1(a1, a1+sizeof(a1)/sizeof(a1[0]));
	vector<int> arr2(a2, a2+sizeof(a2)/sizeof(a2[0]));
	vector<int> arr3(a3, a3+sizeof(a3)/sizeof(a3[0]));
	vector<int> arr4(a4, a4+sizeof(a4)/sizeof(a4[0]));
	Solution solu;
	cout << solu.findPairs(arr1, 2) << endl;
	cout << solu.findPairs(arr2, 1) << endl;
	cout << solu.findPairs(arr3, 0) << endl;
	cout << solu.findPairs(arr4, 0) << endl;
	return 0;
}