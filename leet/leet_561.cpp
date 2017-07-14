#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size();
        //int half_len = len / 2;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < len; i = i+2)
        {
            sum += nums.at(i);
        }
        return sum;
    } 
};

int main()
{
    int a[] = {1,4,3,2};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.arrayPairSum(arr) << endl;
    return 0;
}
