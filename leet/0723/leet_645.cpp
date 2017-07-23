// set S (unordered) contains number from 1 to n, but one number duplicates and another is missing, return [duplicateNum, missingNum]
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        //cout << "come1" << endl;
        sort(nums.begin(), nums.end()); // ascending order
        //cout << "come2" << endl;
        vector<int> res;
        bool find1st = false;
        bool find2nd = false;
        int first = -1, second = -1;
        //cout << "come3" << endl;
        for(int i = 0; i < len; ++i)
        {
            //cout << "come4" << endl;
            if(!find1st && nums[i] < i+1) 
            {
                //cout << "i = " << i << ", nums[i] = " << nums[i] << endl; 
                find1st = true;
                first = nums[i];
            }
            else if(find1st && nums[i] == i + 1)
            {
                //cout << "i = " << i << ", nums[i] = " << nums[i] << endl;
                second = i;
                break;
            }
            if(!find2nd && nums[i] > i+1) 
            {
                //cout << "i = " << i << ", nums[i] = " << nums[i] << endl; 
                find2nd = true;
                second = i + 1;
            }
            else if(find2nd && nums[i] == i + 1)
            {
                //cout << "i = " << i << ", nums[i] = " << nums[i] << endl;
                first = nums[i];
                break;
            }
        }
        // in case the last number is missing
        if(find1st && second == -1) second = len;
        res.push_back(first);
        res.push_back(second);
        return res;
    }
};

int main()
{
    Solution solu;
    // dup 6, miss 11
    int a[] = {3,2,3,4,6,5};//{1,1};//{1,2,3,4,5,6,6,7,8,11,10,9};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    vector<int> res = solu.findErrorNums(arr);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}
