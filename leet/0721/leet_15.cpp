// find all unique triplets in an array that gives the sum of zero
#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // in ascending order
        int len = nums.size();
        vector<vector<int> > res;
        if(len < 3) return res; // empty vvi
        int sum;
        int i = 0;
        for(int i = 0; i < len - 2; ++i)
        {
            int tmp = -nums[i];
            int first = i + 1, last = len - 1;
            while(first < last)
            {
                //cout << "come3, first = " << first << ", last = " << last << endl;
                sum = nums[first] + nums[last];
                // sum of 3 vals are less than zero
                if(sum < tmp) ++first;
                else if(sum > tmp) --last; // sum larger than zero
                else // here is a dead loop
                {
                    vector<int> tmpvec(3, 0);
                    tmpvec[0] = nums[i]; // smallest
                    tmpvec[1] = nums[first]; //middle
                    tmpvec[2] = nums[last]; // largest
                    res.push_back(tmpvec);
                    // fix the bug: find another good group
                    ++first;
                    --last;  
                    // remove duplicates
                    while(first < len && nums[first] == nums[first - 1]) ++first;
                    while(last > i && nums[last] == nums[last + 1]) --last;
                }
            }
            while(i < len - 2 &&  nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

int main()
{
    int a[] = {-1, 0, 1,2,-1,-4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    //cout << "come1" << endl;
    vector<vector<int> > res = solu.threeSum(arr);
    //cout << "come2" << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[0].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //cout << endl;
    return 0;
}
