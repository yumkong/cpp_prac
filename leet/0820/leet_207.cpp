// given a total of n courses labeled from 0 to n - 1, and their prerequisites, determine if it is possible to finish all courses
// solu BFS + toplogical sort
#include <vector>
#include <iostream>
#include <utility> // pair
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // i -> j
        vector<vector<int> > matrix(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            int ready = prerequisites[i].first, pre = prerequisites[i].second;
            if(matrix[pre][ready] == 0) ++indegree[ready]; // keep all unique in degree to ready
            matrix[pre][ready] = 1;
        }
        int count = 0;
        queue<int> qi;
        for(int i = 0; i < indegree.size(); ++i)
        {   // keep all no indegree nodes
            if(indegree[i] == 0) qi.push(i);
        }
        while(!qi.empty())
        {
            int course = qi.front(); qi.pop();
            ++count;
            for(int i = 0; i < numCourses; ++i)
            {
                if(matrix[course][i] != 0)
                {   // when course is i's only prerequisite, push i to queue
                    if(--indegree[i] == 0) qi.push(i);
                }
            }
        }
        return count == numCourses;
    }
};

int main()
{
    vector<pair<int, int> > input({ {1,0}, {0,1} });
    Solution solu;
    cout << solu.canFinish(2, input) << endl;
    return 0;
}
