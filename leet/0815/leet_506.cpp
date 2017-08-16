// givne N scores, find their relative ranks and the people with the top three highest scores are
// awarded "Gold Medal", "Silver Medal" and "Bronze Medal"
// N is positive and <= 10000
// all scores are unique
#include <string>
#include <vector>
#include <iostream>
#include <utility> // pair
#include <algorithm>
using namespace std;

struct Comp{ // sort in descending order
    bool operator()(pair<int, int> x, pair<int,int> y)
    { return x.second > y.second; }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int,int> > vp;
        for(int i = 0; i < len; ++i) vp.push_back({i, nums[i]});
        sort(vp.begin(), vp.end(), Comp());
        vector<string> res(len, "");
        res[vp[0].first] = "Gold Medal";
        if(len >= 2) res[vp[1].first] = "Silver Medal";
        if(len >= 3) res[vp[2].first] = "Bronze Medal";
        for(int i = 3; i < len; ++i) res[vp[i].first] = to_string(i+1);
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({5,4,3,2,1});
    vector<string> res = solu.findRelativeRanks(input);
    for(auto& s: res) cout << s << endl;
    return 0;
}
