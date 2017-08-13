// given a collection of intervals, merge all overlapping intervals
// NOTE that the intervals are not necessarily sorted
// so first need to sort the interval by ascending order by start elem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Comp
{
    bool operator() (Interval x, Interval y) {return (x.start < y.start); }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //stack<Interval, vector<Interval> > st(intervals);
        vector<Interval> res;
        int len = intervals.size();
        if(len <= 0) return res;
        if(len == 1) return intervals;
        sort(intervals.begin(), intervals.end(), Comp());
        //int start = 0, end = len;
        //bool isfirst = true;
        Interval newInterval = intervals[0];
        for(int i = 1; i < len; ++i)
        {
            Interval tmp = intervals[i];
            
            if((tmp.start <= newInterval.end && tmp.end >= newInterval.end) ||
               (tmp.start <= newInterval.start && tmp.end >= newInterval.start) ||
               (newInterval.start <= tmp.end && newInterval.end >= tmp.end) ||
               (newInterval.start <= tmp.start && newInterval.end >= tmp.start))
            {
                //if(isfirst) {start = i; isfirst = false; }
                newInterval.start = min(newInterval.start, tmp.start);
                newInterval.end = max(newInterval.end, tmp.end);
            }
            else if(tmp.start > newInterval.end) // newInterval is not overlap with its follower
            {
                res.push_back(newInterval);
                newInterval = tmp;
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

int main()
{
    //vector<Interval> input({Interval(1,3), Interval(2,6), Interval(8,10),Interval(15,18)});
    vector<Interval> input({Interval(1,4), Interval(0,0)});
    Solution solu;
    vector<Interval> res = solu.merge(input);
    for(auto& itv: res) cout << "[" << itv.start << ", " << itv.end << "]" << endl;
    return 0;
}
