// student attendance accord
// <=1 A, no >2 consecutive L, P is unlimited
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        int m = 1000000007;
        // A[n] : total number of valid records ended with A, of length n
        // P[n] :                                          P, of length n
        // L[n] :                                          L, of length n
        vector<int> A(n + 1, 0);
        vector<int> P(n + 1, 0);
        vector<int> L(n + 1, 0);
        A[1] = 1, P[1] = 1, L[1] = 1;
        L[2] = 3, A[2] = 2, A[3] = 4;
        for(int i = 2; i <= n; ++i)
        {
            P[i] = ((A[i-1] + P[i-1]) % m + L[i-1]) % m;
            if(i > 2) L[i] = ((A[i-1] + P[i-1]) % m + (A[i-2] + P[i-2]) % m) % m;
            if(i > 3) A[i] = ((A[i-1] + A[i-2]) % m + A[i-3]) % m;
        }
        return ((A[n] + P[n]) % m + L[n]) % m;
    }
};

int main()
{
    Solution solu;
    cout << solu.checkRecord(2) << endl;
    return 0;
}
