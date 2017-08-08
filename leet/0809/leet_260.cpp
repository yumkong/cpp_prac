//given an int array, two elems appear only once and other elems appear exactly twice
// find the two lems that appear once in O(1) time and O(1) space
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            diff ^= nums[i];
        }
        // get the lowest '1' bit
        // corner case: when diff = min_int (1<<31), -diff = diff, so the lowest '1' bit is on 32th pos
        diff &= -diff;
        vector<int> res(2, 0);
        for(int i = 0; i < len; ++i)
        {
            if(diff & nums[i]) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> arr({1,2,1,3,2,5});
    vector<int> res = solu.singleNumber(arr);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
