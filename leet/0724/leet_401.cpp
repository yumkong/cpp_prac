// given a non-negative integer n which represents the number of LEDs that are currently on,
// return all possible times the watch could represent
// hour not have any leading zero, minute may has leading zero to make it two digits
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if(num == 0)
        {
            res.push_back("0:00");
            return res;
        }
        if(num > 8) return res; // cannot represent any
        int a1[] = {8,4,2,1};  
        int a2[] = {32, 16, 8, 4,2,1};
        vector<int> hours(a1, a1 + sizeof(a1)/sizeof(a1[0]));
        vector<int> minutes(a2, a2 + sizeof(a2) / sizeof(a2[0]));
        for(int i = 0; i <= 3; ++i)
        {
            if(num - i > 5 || num - i < 0) continue;
            vector<int> hourlst = generateDigit(hours, i);
            vector<int> minutelst = generateDigit(minutes, num - i);
            for(int j = 0; j < hourlst.size(); ++j)
            {
                if(hourlst[j] >= 12) continue;
                for(int k = 0; k < minutelst.size(); ++k)
                {
                    if(minutelst[k] >= 60) continue;
                    string minu = (minutelst[k] < 10)?("0" + to_string(minutelst[k])) : to_string(minutelst[k]);
                    res.push_back(to_string(hourlst[j]) + ":" + minu);
                }
            }
        } 
        return res;
    }
    vector<int> generateDigit(vector<int> times, int count)
    {
        vector<int> res;
        helper(times, count, 0, 0, res);
        return res;
    }
    void helper(vector<int>& times, int count, int pos, int sum, vector<int>& res)
    {
        if(count == 0) 
        {
            res.push_back(sum); 
            return;
        }
        // if not statisfying the condition (i < times.size()): stop recursing,
        // and also no contribution to res
        for(int i = pos; i < times.size(); ++i)
        {
            helper(times, count - 1, i + 1, sum + times[i], res);
        }
    } 

};

int main()
{
    Solution solu;
    vector<string> res = solu.readBinaryWatch(1); // 0:00
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
