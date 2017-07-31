//thanks han35
//First assume that we have no money, so buy1 means that we have to borrow money from others, we want to borrow less so that we have to make our balance as max as we can(because this is negative).
// -- sell1 means we decide to sell the stock, after selling it we have price[i] money and we have to give back the money we owed, so we have price[i] - |buy1| = prices[i ] + buy1, we want to make this max.
// -- buy2 means we want to buy another stock, we already have sell1 money, so after buying stock2 we have buy2 = sell1 - price[i] money left, we want more money left, so we make it max
// -- sell2 means we want to sell stock2, we can have price[i] money after selling it, and we have buy2 money left before, so sell2 = buy2 + prices[i], we make this max.
// -- So sell2 is the most money we can have.
#include <iostream>
#include <vector>
#include <climits> // INT_MIN
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int sell1 = 0, sell2 = 0;
        int buy1 = INT_MIN, buy2 = INT_MIN;
        for(int i = 0; i < len; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
            // observe
            cout << buy1 << ", " << sell1 << ", " << buy2 << ", " << sell2 << endl;
        }
        return sell2;
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
