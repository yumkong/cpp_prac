// given an array, move all 0's to the end of it while maitaining the relative order of the array's non-zero elems
// must do in-place without making a copy of the array
// minize the number of operations
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        vector<int>::iterator it = nums.begin();
        while(it != nums.end())
        {
            if(*it == 0) it = nums.erase(it);
            else ++it;
        }
        int newlen = nums.size();
        if(newlen < len) nums.insert(nums.end(), len - newlen, 0);
    }
};

int main()
{
    Solution solu;
    vector<int> arr({0,1,0,3,12});
    solu.moveZeroes(arr);
    for(auto &i: arr) cout << i << " ";
    cout << endl;
    return 0;
}
