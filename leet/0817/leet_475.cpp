// compute the minimum radius of heaters that can warm all the houses
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int len1 = houses.size();
        int len2 = heaters.size(); 
        if(len2 == 0) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0, idx = 0;
        for(int i = 0; i < houses.size(); ++i)
        {
            while(idx + 1 < heaters.size() 
                  && (abs(heaters[idx + 1] - houses[i]) <= abs(heaters[idx] - houses[i])))
            { ++idx; }
            radius = max(radius, abs(heaters[idx] - houses[i]));
        }
        return radius;
    }
};

int main()
{
    Solution solu;
    vector<int> houses({1,2,3,4});
    vector<int> heaters({1,4});
    cout << solu.findRadius(houses, heaters) << endl;
    return 0;
}
