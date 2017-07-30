//given an array where arr[i] the price of a given stock on day i
// only permitted to complete at most one transaction (buy one and sell one share of the stock)
// find the maximum profit
// => find the max diff (min, max) pair
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 0) return 0;
        int maxPro = 0, minPrice = prices[0];
        for(int i = 1; i < len; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};

int main()
{
    int a[] = {7,1,5,3,6,4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.maxProfit(arr) << endl;
    return 0;
}
