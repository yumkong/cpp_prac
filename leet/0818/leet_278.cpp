// given a sequence of product versions [1,2,...,n], the first bad version will cause all later versions bad
// find the first bad version with minimal number of calls
// my solu: very basic binary search
#include <iostream>
using namespace std;
#define BAD_START 1702766719
// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    return version >= BAD_START;
}

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1 && isBadVersion(1)) return 1;
        int left = 1, right = n;
        long mid = 0;
        //distribution: [not bad] left .... right [bad]
        while(left <= right)
        {
            // need forces cast, otherwise already overflow when assigning to mid
            mid = ((long)left + (long)right) >> 1;
            if(isBadVersion((int)mid)) right = mid - 1;
            else left = mid + 1;
            //cout << "mid = " << mid << endl;
        }
        return left;
    }
};

int main()
{
    Solution solu;
    cout << solu.firstBadVersion(2126753390) << endl;
    return 0;
}
