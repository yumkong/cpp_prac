// given a total of n courses labeled from 0 to n - 1, and their prerequisites, return the order of cause you should take to finish all courses, if impossible, return an empty array
// solu BFS + toplogical sort
#include <vector>
#include <iostream>
#include <utility> // pair
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        {   // keep all no indegree nodes (also mean: no prerequisite needed)
            if(indegree[i] == 0) qi.push(i);
        }
        vector<int> res, emptyres;
        while(!qi.empty())
        {
            int course = qi.front(); qi.pop();
            ++count;
            res.push_back(course);
            for(int i = 0; i < numCourses; ++i)
            {
                if(matrix[course][i] != 0)
                {   // when course is i's only prerequisite, push i to queue
                    if(--indegree[i] == 0) qi.push(i);
                }
            }
        }
        if(count == numCourses) return res;
        else return emptyres;
    }
};

int main()
{
    vector<pair<int, int> > input({ {1,0}, {2,0}, {3,1}, {3,2} });
    Solution solu;
    vector<int> res = solu.findOrder(4, input);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
