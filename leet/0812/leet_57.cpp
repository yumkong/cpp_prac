// insert interval: given a set of non-overlapping intervals, insert a new interval into the intervals
// and merge them if necessary
// ASSUME: the intervals were initially sorted according to their start times
#include <vector>
#include <iostream>
//#include <stack>
using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        //stack<Interval, vector<Interval> > st(intervals);
        vector<Interval> res(intervals.begin(), intervals.end());
        int len = intervals.size();
        if(len <= 0) { intervals.push_back(newInterval); return intervals; }
        int start = 0, end = len;
        bool isfirst = true;
        for(int i = 0; i < len; ++i)
        {
            Interval tmp = intervals[i];
            
            if((tmp.start <= newInterval.end && tmp.end >= newInterval.end) ||
               (tmp.start <= newInterval.start && tmp.end >= newInterval.start) ||
               (newInterval.start <= tmp.end && newInterval.end >= tmp.end) ||
               (newInterval.start <= tmp.start && newInterval.end >= tmp.start))
            {
                if(isfirst) {start = i; isfirst = false; }
                newInterval.start = min(newInterval.start, tmp.start);
                newInterval.end = max(newInterval.end, tmp.end);
            }
            else if(tmp.start > newInterval.end)
            {
                end = i; break;
            }
            else if(tmp.end < newInterval.start)
            {
                if(isfirst) ++start;
            }
        }
        cout << "start = " << start << ", end = " << end << endl;
        // the interval not overlap with existing ones
        if(start == end) res.insert(res.begin() + start, newInterval);
        else if(end == start + 1) // only start-th elem need to be updated
        { 
            res[start] = newInterval; 
        }
        else if(start > end) // insert at the end
        {
            res.push_back(newInterval);
        }
        else 
        {
            res.erase(res.begin() + start, res.begin() + end);
            res.insert(res.begin() + start, newInterval);
        }
        return res;
    }
};

int main()
{
    //vector<Interval> input({Interval(1,2), Interval(3,5), Interval(6,7),Interval(8,10),Interval(12,16)});
    //Interval newitv(4,9);
    //vector<Interval> input({Interval(2,6), Interval(7,9)});
    //Interval newitv(15,18);
    //vector<Interval> input({Interval(1,5)});
    //Interval newitv(2,3);
    vector<Interval> input({Interval(2,7), Interval(8,8), Interval(10,10),Interval(12,13),Interval(16,19)});
    Interval newitv(9,17);
    Solution solu;
    vector<Interval> res = solu.insert(input, newitv);
    for(auto& itv: res) cout << "[" << itv.start << ", " << itv.end << "]" << endl;
    return 0;
}
