// given a total of n courses labeled from 0 to n - 1, and their prerequisites, determine if it is possible to finish all courses
#include <vector>
#include <iostream>
#include <utility> // pair
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
    }
};

int main()
{
    vector<vector<int> > input({ {1,0}, {0,1} });
    Solution solu;
    cout << solu.canFinish(2, input) << endl;
    return 0;
}
