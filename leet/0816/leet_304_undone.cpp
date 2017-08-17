// given an int array, find the sum of elements between index i and index j
// the update(i, val) modifies nums by updating the element at index i to val (only this function change the array)
// assume the number of calls to update and sumRange function is distributed evenly
#include <vector>
#include <iostream>
using namespace std;

class NumArray {
private:
    vector<int> arr;
public:
    NumArray(vector<int> nums) {
        arr.assign(nums.begin(), nums.end());
    }
    
    void update(int i, int val)
    {
        arr[i] = val;
    }
 
    int sumRange(int i, int j) {
        int res = 0;
        for(int k = i; k <= j; ++k) res += arr[k];
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
