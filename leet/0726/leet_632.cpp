// given k list of sorted integers in ascending order, find the smallest range that includes at least one number from each of the k lists
//
// the given list may contain duplicates. so ascending order means >= here
// 1<= k <= 3500
// -10^5 <= value of each list elem <= 10^5
//
// inspired solu: keep a priority queue of iterators(pointers) which points to the current head of row
#include <iostream>
#include <vector>
#include <queue> // priority_queue and queue are both here
#include <climits> // INT_MAX, INT_MIN
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        struct comp{
            bool operator()(pair<vi, vi> p1, pair<vi, vi> p2)
            {
                // . has higher priority that dereference
                return *p1.first > *p2.first;
            }
        };
        int lo = INT_MAX, hi = INT_MIN;
        // can put a sequecial container as the 2nd type of argus
        // so that pq can be initialized by a vector<pair<vi,vi> >
        priority_queue<pair<vi, vi>, vector<pair<vi, vi> >, comp> pq;
        for(auto& row: nums)
        {
            // keep the min and max of each list's first element
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            // push the iterator pair of each list to the priorityqueue which sort the lists
            // according to the **descending** order of their 1st element
            // NOTE the highest priority element is always rightmost (here is the list with smallest
            // first element)
            pq.push({row.begin(), row.end()});
        }
        // init the answer as the min and max of the first element, then refine
        vector<int> ans = {lo, hi};
        int cnt = 0;
        while(true)
        {
            // for debug/ observe
            //cout << "Iter " << ++cnt << ": lo = " << lo << ", hi = " << hi << endl; 
            // pop the list with lowest first elem (the end of the pri)
            auto p = pq.top(); pq.pop();// auto: type deduction
            ++p.first; // point to the 2nd elem of this list
            // if has come to the end, break
            if(p.first == p.second) break;
            // push back to the priority list, now it may not be at the end
            pq.push(p);
            // most important 4 lines
            lo = *pq.top().first; // highest priority list's begin iter
            hi = max(hi, *p.first); // update highest element
            if(hi - lo < ans[1] - ans[0]) ans = {lo, hi};
        }
        return ans;
    }
};

int main()
{
    Solution solu;
    int a1[] = {4, 10, 15, 24, 26};
    int a2[] = {0, 9, 12, 20};
    int a3[] = {5, 18, 22, 30};
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    vector<vector<int> > arr;
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    vector<int> res = solu.smallestRange(arr);
    cout << "range = [" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}
