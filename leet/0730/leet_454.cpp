// given 4 lists of ints A,B,C,D, compute how many tuples (i,j,k,l) s.t. 
// A[i] + B[j] + C[k] + D[l] = 0
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        if(len <= 0) return 0; // no such tuple
        map<int, int> mp;
        for(auto& a:A)
        {
            for(auto& b:B) ++mp[a + b];  
        }
        int cnt = 0;
        for(auto& c:C)
        {
            for(auto& d:D) 
            {
                // NOTE here!!!
                if(mp.count(-c-d)) cnt += mp[-c-d];
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> A({1,2});
    vector<int> B({-2,-1});
    vector<int> C({-1,2});
    vector<int> D({0, 2});
    Solution solu;
    cout << solu.fourSumCount(A, B, C, D) << endl;
    return 0;
}
