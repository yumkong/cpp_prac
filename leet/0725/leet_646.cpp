// given n pairs of numbers, with 1st number less than the second
// for (a, b) and (c,d), if b < c, we call that (c,d) follows (a,b) to form a chain
// find the length of the longest chain
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool pairCompare(vector<int> vi1, vector<int> vi2)
{
    return vi1[0] < vi2[0];
}

class Solution {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        int len = pairs.size();
        if(len == 1) return 1;
        // sort pairs according to the ascending order of the first number
        sort(pairs.begin(), pairs.end(), pairCompare);
        int maxval = 0;
        // store the chain length that each pair can achieve
        // init each dp element to 1: at least itself is a valid pair
        vector<int> dp(len, 1);  // ##O(n) space##
        // ### O(n ^ 2) time ###
        for(int i = 1; i < len; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(pairs[i][0] > pairs[j][1] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                } 
            } 
        } 
        for(int i = 0; i < len; ++i)
        {
            if(maxval < dp[i]) maxval = dp[i];
        }
        return maxval;
    }
    //bool pairCompare(vector<int> vi1, vector<int> vi2)
    //{
    //    return vi1[0] < vi2[0];
    //}
};

//bool pairCompare(vector<int>& vi1, vector<int>& vi2)
//{
//    return vi1[0] < vi2[0];
//}


int main()
{
    Solution solu;
    int a1[] = {1,2};
    int a2[] = {2,3};
    int a3[] = {3,4};
    vector<int> arr1(a1, a1+sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2+sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3+sizeof(a3)/sizeof(a3[0]));
    vector<vector<int> > pairs; 
    pairs.push_back(arr1);
    pairs.push_back(arr2);
    pairs.push_back(arr3);
    cout << solu.findLongestChain(pairs) << endl;
    return 0;
}
