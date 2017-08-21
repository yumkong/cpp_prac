//given an int array, return the number of range sums in [lower, upper] inclusive
// heavily inspired by pepsi's solution: thanks!
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sum(len + 1, 0);
        for(int i = 0; i < len; ++i)
        {
            sum[i+1] = sum[i] + nums[i];
        } 
        return helper(sum, 0, len+1, lower, upper);
    }
    int helper(vector<long>& sum, int start, int end, int lower, int upper)
    {
        // only 1 elem, so the count-pair = 0
        if(end - start <= 1) return 0;
        int mid = (start + end) / 2;
        int count = helper(sum, start, mid, lower, upper)
                  + helper(sum, mid, end, lower, upper);
        // how many in [start, end)
        vector<long> cache(end - start, 0);
        // use len to record the merged length
        int j = mid, k = mid, t = mid, len = 0;
        for(int i = start, r = 0; i < mid; ++i, ++r)
        {
            // compare the second half to each element (i) of first half
            // number of below lower bounds 
            while(k < end && sum[k] - sum[i] < lower) ++k;
            // number of equal to or below upper bounds
            while(j < end && sum[j] - sum[i] <= upper) ++j;
            // record the sum[t] int the second half when it is lower than sum[i]
            while(t < end && sum[t] < sum[i]) cache[r++] = sum[t++];
            // finally add sum[i], so at least cache has 1 element sum[i]
            cache[r] = sum[i];
            len = r;
            count += j - k; // number of satisfied pairs from two halves
        }
        //because after you copy it to cache, you then copy it back to sums. The reason that you don't need to copy the rest of array is because it doesn't change.
        //For example, you are merging sums = [1 3 5 6 2 4 7 8]. The result should be [1 2 3 4 5 6 7 8] and [7 8] doesn't change. Thus after you copied 123456 to cache you don't need to copy [7 8].
        // me: why this merge is necessary? because the above 3 whiles is based on the merged logical, otherwise it cannot stand
        for(int i = 0; i <= len; ++i) sum[start + i] = cache[i];
        return count;
    }
};

int main()
{
    Solution solu;
    vector<int> input({-1, 1});
    cout << solu.countRangeSum(input, 0, 0) << endl;
    return 0;
}
