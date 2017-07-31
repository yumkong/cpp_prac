// given two array, compute their intersection
// each element must be unique (only once regardless of the occurence in arrays), the result can in any order
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0 || len2 == 0) return res;
        map<int, int> mp1, mp2;
        for(int i: nums1) ++mp1[i];
        for(int i: nums2) ++mp2[i];
        for(pair<int, int> tmp: mp1)
        { 
            // nums2 not contain this number
            if(mp2.count(tmp.first) == 0) continue;
            else
            {
                int num = min(mp2[tmp.first], tmp.second);
                res.insert(res.end(), 1, tmp.first);
            }
        } 
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> nums1({1,2,2,1});
    vector<int> nums2({2,2});
    vector<int> res = solu.intersection(nums1, nums2);
    for(int i: res) cout << i << " ";
    cout << endl;
    return 0;
}
