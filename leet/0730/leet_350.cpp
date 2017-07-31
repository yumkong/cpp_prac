// given two arrays, compute their intersection
// result can be in any order, but each element in the result should appear as many times as in both arrays
// Q1: What if the given array is already sorted? How would you optimize your algorithm?
// Q2: What if nums1's size is small compared to nums2's size? Which algorithm is better?
// Q3: What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
                res.insert(res.end(), num, tmp.first);
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
    vector<int> res = solu.intersect(nums1, nums2);
    for(int i: res) cout << i << " ";
    cout << endl;
    return 0;
}
