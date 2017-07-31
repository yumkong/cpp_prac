// distribute an even integer array into two havles where one half contain as many as different ints
// return the number of different ints
#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int len = candies.size();
        set<int> si(candies.begin(), candies.end());
        return min((int)si.size(), len / 2);
    }
};

int main()
{
    int a[] = {1,1,2,3};
    vector<int> arr(a, a+ sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.distributeCandies(arr) << endl;
    return 0;
}
