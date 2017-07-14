#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> ch_cnt;
        int cnt = 0;
        //for(auto e: tasks)
        vector<char>::iterator cit;
        for(cit = tasks.begin(); cit != tasks.end(); ++cit)
        {
            ++ch_cnt[*cit];
            // ++cn_cnt[e];
            cnt = max(ch_cnt[*cit], cnt);
        }
        int step_num = (n + 1) * (cnt - 1);
        //for(auto e: ch_cnt) 
        map<char, int>::iterator mit;
        for(mit = ch_cnt.begin(); mit != ch_cnt.end(); ++mit)
        {         
            // NOTE first and second is a member, not function
            //if(e.second == cnt) ++step_num;
            //if((*mit).second == cnt) ++step_num; // ok1
            if(mit->second == cnt) ++step_num; //ok2
        }
        return max((int)tasks.size(), step_num);
    }
};

int main()
{
    char a[] = {'A','A','A','B','B','B'}; 
    vector<char> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.leastInterval(arr, 2) << endl;
    return 0;
}
