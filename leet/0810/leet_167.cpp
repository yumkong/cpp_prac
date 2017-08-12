// given a sorted int array (ascending order), find two nums that add up to a target number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> res;
        if(len <= 1) return res;
        int left = 0, right = len - 1;
        while(left < right)
        {
            int tmp = numbers[left] + numbers[right];
            if(tmp == target) break;
            else if(tmp < target) ++left;
            else --right;
        }
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,7,11,15});
    vector<int> res = solu.twoSum(input, 9);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
