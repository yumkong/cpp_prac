// given an array where arr[i] the price of a given stock on day i
// permitted to complete at multiple transactions (buy one and sell one share of the stock)
// find the maximum profit
// must sell the stock before buying again
#include <iostream>
#include <vector>
#include <stack>
#include <utility> // pair
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        stack<pair<int, int> > sp;
        sp.push(make_pair(prices[0], prices[0]));
        for(int i = 1; i < len; ++i)
        {
            pair<int,int> tmp = sp.top(); 
            if(tmp.second < prices[i])
            {
                sp.pop();
                tmp.second = prices[i];
                sp.push(tmp); // push new pair to stack
            }
            else
            {
                sp.push(make_pair(prices[i], prices[i]));
            }
        }
        int sum = 0;
        while(!sp.empty())
        {
            pair<int,int> tmp = sp.top(); sp.pop();
            sum += (tmp.second - tmp.first);
        }
        return sum;
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
