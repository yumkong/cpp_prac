// merge sorted int arrays, given two arrays and their original length
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt1 = m - 1;
        int pt2 = n - 1;
        int ptall = m + n - 1;
        while(pt1 >= 0 && pt2 >= 0)
        {
            if(nums1[pt1] > nums2[pt2]) nums1[ptall--] = nums1[pt1--];
            else nums1[ptall--] = nums2[pt2--];
        }
        if(pt2 >= 0)
        {
            while(pt2 >= 0) nums1[ptall--] = nums2[pt2--];
        }
    }
};

int main()
{
    Solution solu;
    vector<int> nums1({1,3,5,7,9});
    vector<int> nums2({2,4,6,8,10});
    int len1 = nums1.size(), len2 = nums2.size();
    nums1.insert(nums1.end(), len2, 0);
    solu.merge(nums1, len1, nums2, len2);
    for(auto &i: nums1) cout << i << " ";
    cout << endl;
    return 0;
}
