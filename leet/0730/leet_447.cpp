// given n points in the x-y plane that are all pairwise distinct, find all "boomerang":
// a tuple of points (i,j,k) s.t. dist(i, j) == dist(i, k)
// NOTE: order of the tuple matters !!!
// n <= 500
// coords in [-10000, 10000]

#include <vector>
#include <utility>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
        int len = points.size();
        if(len <= 2) return 0;
        map<int, int> mp; // <dist, count>
        int res = 0;
        for(int i = 0; i < len; ++i)
        {
            for(int j = 0; j < len; ++j)
            {
                if(j == i) continue;
                int dist = (points[i].first - points[j].first) * (points[i].first - points[j].first)
                         + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                ++mp[dist];
            }
            for(pair<int, int> pi: mp)
            {
                if(pi.second >= 2) 
                {
                  //  cout << pi.second << endl;
                    // the order matter!!!
                    res += pi.second * (pi.second - 1);
                }
            }
            mp.clear(); // remove all elements from the map
        }
        return res;
    }
};

int main()
{
    vector<pair<int, int> > input({
        {0,0}, {1,0}, {2,0}
    });
    Solution solu;
    cout << solu.numberOfBoomerangs(input) << endl;
    return 0;
}
