// given two list of restaurant names, find the common name with the least index sum
// the length of two list in [1,1000]
// the length of name strings in [1,30]
// index starting from 0 to len-1
// no duplicated name strings in any of the two lists
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> resta;
        int len1 = list1.size();
        int len2 = list2.size();
        vector<string> restr;
        int res = ~(1<<31); // init as max_int
        // NOTE map has no push_back, but insert
        for(int i = 0; i < len1; ++i) resta.insert({list1[i], i});
        for(int i = 0; i < len2; ++i) 
        {
            if(resta.count(list2[i])) res = min(res, i + resta[list2[i]]);
        }
        for(int i = 0; i < len2; ++i)
        {
            if(resta.count(list2[i]) && res == i+resta[list2[i]]) 
                restr.push_back(list2[i]);
        }
        return restr;
    }
};

int main()
{
    // use c++11 for convenience
    vector<string> list1({"Shogun", "Tapioca Express", "Burger King", "KFC"});
    vector<string> list2({"KFC", "Shogun", "Burger King"});
    Solution solu;
    vector<string> res = solu.findRestaurant(list1, list2);
    for(auto& ss: res) cout << ss << endl;
    return 0;
}
