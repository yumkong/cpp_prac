// skyline problem
// the geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 <= Li, Ri < INT_MAX, 0 < Hi <= INT_MAX, and Ri - Li > 0. 
//Assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue> // priority_queue
using namespace std;

struct Comp{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if(p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        vector<pair<int, int> > height;
        for(int i = 0; i < buildings.size(); ++i)
        {
            // give start point (-height)
            height.push_back({buildings[i][0], -buildings[i][2]});
            // give end point (+height)
            height.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(height.begin(), height.end(), Comp());
        priority_queue<int> pq; // retrieve max elem at top
        pq.push(0);
        int prev = 0;
        for(int i = 0; i < height.size(); ++i)
        {   // if left edge push to pq, otherwise pop from pq
            if(height[i].second < 0) pq.push(-height[i].second);
            else pq.pop(height[i].second); // pq has no remove function!!!
            int cur = pq.top();
            if(prev != cur)
            {
                res.push_back({height[i].first, cur});
                prev = cur;
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> input({ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} }); 
    vector<pair<int, int> > res = solu.getSkyline(input);
    for(auto &p: res) cout << "[" << p.first << ", " << p.second << "]" << endl;
    return 0;
}
