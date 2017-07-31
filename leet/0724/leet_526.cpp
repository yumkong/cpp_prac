// given N integers from 1 to N, a beautiful arrangment is a array constructed by these N numbers,
// where for the ith (1 <= i <= N) positions, one of the following two conditions satifiied:
// (1) arr[i-1] % i == 0  (NOTE: index i-1 is ith position)
// (2) i / arr[i-1] == 0
// find the number of the beautiful arrangement
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        if(N == 0) return 0;
        vector<int> nums;
        for(int i = 0; i <= N; ++i) nums.push_back(i);
        //initialize count (member val)
        count = 0;
        helper(nums, N);
        return count; 
    }
    void helper(vector<int> &nums, int start)
    {
        if(start == 0)
        {
            ++count;
            return;
        }
        for(int i = start; i > 0; --i)
        {
            // the first case has no change to the orignal array
            swap(nums, start, i); 
            // do business
            if(nums[start] % start == 0 || start % nums[start] == 0) 
            {
                helper(nums, start - 1);
            }
            // at the end of this ith iter, swap back
            swap(nums, i, start);
        }
    }
    void swap(vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
private:
    int count;
};

int main()
{
    Solution solu;
    cout << solu.countArrangement(12) << endl;
    return 0;
}
