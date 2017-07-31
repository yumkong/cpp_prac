//hamming distance: the number of positions at which the corresponding bits are different
//given an array, find the total hamming distance between all pairs of the given numbers
// the ints are [0, 10^9] => non-negative ints!!!
// length of the array: <= 10000
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        int dist = 0;
        
        for(int i = 0; i < 32; ++i)
        {
            int cnt1 = 0;
            for(int j = 0; j < len; ++j)
            {
                if(nums[j] >> i & 0x1 == 1) ++cnt1;
            }
            // hamming distance of ith bit
            dist += cnt1 * (len - cnt1);
            //cout << "i = " <<  i <<  ", cnt1 = " << cnt1 << endl;
        }
        return dist;
    }
};

int main()
{
    int a[] = {2,14, 4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.totalHammingDistance(arr) << endl;
    return 0;
}
