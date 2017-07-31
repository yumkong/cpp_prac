// given a non-empty array of integers, return the k most frequent elements.
// assume k is always valid
// time complexity must be better than O(nlogn) where n the array's size
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <queue> // priority_queue
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        if(k <= 0) return res;
        map<int, int> mp; // <num, count>
        for(int i: nums) ++mp[i];
        priority_queue<pair<int, int> > pq; // <count, num>
        for(pair<int, int> i: mp) 
        {
            pq.push({i.second, i.first});
            if(pq.size() > mp.size() - k) // already contain at least one of the k-most frequent nums
            {
                pair<int, int> tmp = pq.top(); pq.pop();
                res.push_back(tmp.second);
            }
        }
        // NOTE the element in res is unordered, aka necessarily in descending order according to freuqency
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,1,1,2,2,3});
    vector<int> res = solu.topKFrequent(input, 2);
    for(int i:res) cout << i << " ";
    cout << endl;
    return 0;
}
