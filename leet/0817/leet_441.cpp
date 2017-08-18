// binary search question
// given n coins to form a staircase shape, where every k-th row must have exactly k coins
// return total num of full staircase row that can be formed
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int left = 0, right = n, mid = n / 2;
	while(left + 1 < right)
	{
            // here must cast conversion, otherwise res receives negative
	    long res = (long)mid * ((long)mid + 1) / 2;
            // 0817: here we use a conservative way to enclose mid in between left and right
	    if(res > (long)n) right = mid;
	    else if(res < (long(n))) left = mid;
	    else return mid;
	    mid = (left + right) / 2;
	    //cout << "mid = " << mid << endl;
	}
	//cout << "left = " << left << ", right = " << right << endl;
	return left;
    }
};

int main()
{
	Solution solu;
        //cout << sizeof(int) << ", long = " << sizeof(long) << endl;
	cout << solu.arrangeCoins(1804289383) << endl; // 5
	return 0;
}
