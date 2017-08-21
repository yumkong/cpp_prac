// find the kth largest element in an unsorted array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[len - k];
    }
};

int main()
{
    Solution solu;
    vector<int> input({3,2,1,5,6,4});
    cout << solu.findKthLargest(input, 2) << endl;
    return 0;
}
