// next permutation
// rearranges number into the lexicographically next greater permutation of numbers
// if impossible, return lowest posible order
// NOTE: replacement must be done in-place with O(1) memory
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        
    }
};

int main()
{
    vector<int> input({1,2,3,4,5,6});
    Solution solu;
    solu.nextPermutation(input);
    for(auto& i: input) cout << i << " ";
    cout << endl;
    return 0;
}

