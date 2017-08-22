// skyline problem
// the geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 <= Li, Ri < INT_MAX, 0 < Hi <= INT_MAX, and Ri - Li > 0. 
//Assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//For each iteration, we first find the current process time, which is either the next new building start time or the end time of the top entry of the live queue. If the new building start time is larger than the top one end time, then process the one in the queue first (pop them until it is empty or find the first one that ends after the new building); otherswise, if the new building starts before the top one ends, then process the new building (just put them in the queue). After processing, output it to the resulting vector if the height changes. Complexity is the worst case O(NlogN)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue> // priority_queue
using namespace std;

/* struct Comp{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if(p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
}; */

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        priority_queue<pair<int, int> > heap; // <height, endpos>
        int cur = 0, len = buildings.size();
        while(cur < len || !heap.empty())
        {   
	        int curX;
			// no intersection with previous max height building
			if(cur == len || !heap.empty() && heap.top().second < buildings[cur][0])
			{
				curX = heap.top().second;
				// find the downstair for the previous max height building:
                // now heap.top().second() > curX
				while(!heap.empty() && heap.top().second <= curX) heap.pop();
			}
			else  // intersect with previous max height building 
			{
				curX = buildings[cur][0]; // starting pos of a building
				// add all new buildings (height, endpos) to the heap, to find the maxHeight
				while(cur < len && buildings[cur][0] == curX)
				{
					heap.push({buildings[cur][2], buildings[cur][1]});
					++cur;
				}
			}
			int curH = (heap.empty()) ? 0 : heap.top().first;
			if(res.empty() || res.back().second != curH) res.push_back({curX, curH});
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
