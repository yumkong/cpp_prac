// given a sorted int array without duplicates, return the summary of its ranges
// e.g. [0,1,2,4,5,7] => ["0->2","4->5","7"]
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vs;
		int len = nums.size();
		if(len == 0) return vs;
		int prev = nums[0], acc = 0;
		string s;
		for(int i = 1; i < len; ++i)
		{
			if(nums[i] == prev + acc + 1) ++acc;
			else
			{
			    if(acc == 0) s = to_string(prev);
				else s = to_string(prev) + "->" + to_string(prev + acc);
				vs.push_back(s);
				prev = nums[i];
				acc = 0;
			}
		}
		if(acc == 0) s = to_string(prev);
		else s = to_string(prev) + "->" + to_string(prev + acc);
		vs.push_back(s);
		return vs;
    }
};

int main()
{
	int a[] = {0,1,2,4,5,7};
	vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    vector<string> res = solu.summaryRanges(arr);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}