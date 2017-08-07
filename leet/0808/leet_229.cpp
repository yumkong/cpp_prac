// given an int array of size n, find all elems that appear more than floor(n/3) times
// should run O(n) time and O(1) space
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
    }
};

int main()
{
    vector<int> arr({1,1,1,3,3,2,3,3,3,4,5,6});
    Solution solu;
    vector<int> res = solu.majorityElement(arr);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return;
}
