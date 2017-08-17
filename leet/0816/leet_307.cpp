// given an int array, find the sum of elements between index i and index j
// the update(i, val) modifies nums by updating the element at index i to val (only this function change the array)
// assume the number of calls to update and sumRange function is distributed evenly
// idea: use square root (sqrt) decomposition
#include <vector>
#include <iostream>
#include <cmath> //sqrt
using namespace std;

class NumArray {
private:
    int bnum;
    vector<int> blksum;
    vector<int> arr;
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        // avoid empty input
        if(len > 0)
        {
            arr = nums;
            double sqr = sqrt(len);
            bnum = (int)ceil(len / sqr); // how many sqrt blocks
            blksum.assign(bnum, 0);
            for(int i = 0; i < len; ++i)
            {
                blksum[i / bnum] += nums[i];
            }
        }
    }
    
    void update(int i, int val)
    {
        int bidx = i / bnum;
        // update block
        blksum[bidx] = blksum[bidx] - arr[i] + val;
        // update individual element
        arr[i] = val;
    }
 
    int sumRange(int i, int j) {
        int res = 0;
        int startb = i / bnum, endb = j / bnum;
        // if in the same block => not so long, directly sum them
        if(startb == endb) 
        {
            for(int k = i; k <= j; ++k) res += arr[k];
        }
        else
        {
            for(int k = i; k <= (startb + 1) * bnum - 1; ++k) res += arr[k];
            for(int k = startb + 1; k <= endb - 1; ++k) res += blksum[k];
            for(int k = endb * bnum; k <= j; ++k) res += arr[k];
        }
        return res;
    }
};

int main()
{
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    NumArray obj(nums);
    obj.update(2, 66);
    cout << obj.sumRange(0, 2) << endl;
    return 0;
}
