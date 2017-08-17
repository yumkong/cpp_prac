// given an int array, find the sum of elements between index i and index j
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
    cout << obj.sumRange(0, 2) << endl;
    return 0;
}
