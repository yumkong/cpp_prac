// check whether an integer (signed) is a power of 4
// could do without loops/ recursion
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0) return false;
        if(num == 0 || num == 1) return true;
        int max_int = ~(1<<31);
        int left = 0, right = max_int;
        int res;
        bool flag = helper(left, right, res, num);
        if(flag) return helper(left, res, res, res);
        else return false;
    }
    bool helper(int left, int right, int &res, int num)
    {
        bool flag;
        int mid;
        //cout << "come $$$" << endl;
        while(left < right)
        {
            //cout << "mid = " << mid << ", num = " << num << endl;
            //cout << "left = " << left << ", right = " << right << endl;
            mid = (left + right) / 2;
            if(mid <= 1) {flag = false; break;}
            if(mid > num / mid)
            {
                if((mid - 1) > num/ (mid - 1)) right = mid - 1;
                else if((mid - 1) < num/ (mid - 1))
                {
                    flag = false;
                    break;
                }
                else // NOTE this has error potential!!! mid * mid may not be num due to integer division
                {
                    res = mid - 1;
                    flag = (res * res == num);
                    break;
                }
            }
            else if(mid < num / mid)
            {
                if((mid + 1) > num / (mid + 1))
                { 
                    flag = false;
                    break;
                }
                else if((mid + 1) < num/ (mid + 1)) left = mid + 1;
                else
                {
                    res = mid + 1;
                    flag = (res * res == num);
                    break;
                }
            }
            else
            {
                res = mid;
                flag = (res * res == num);
                break;
            }
        }
        return flag;
    }
};

int main()
{
    Solution solu;
    cout << solu.isPowerOfFour(16) << endl;
    return 0;
}
