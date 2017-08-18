// binary search question
// given n coins to form a staircase shape, where every k-th row must have exactly k coins
// return total num of full staircase row that can be formed
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n, mid = n / 2;
		while(left + 1 < right)
		{
			long res = mid * (mid + 1) / 2;
			if(res > (long)n) right = mid - 1;
			else if(res < (long(n))) left = mid + 1;
			else return mid;
			mid = (left + right) / 2;
			cout << "mid = " << mid << endl;
		}
		cout << "left = " << left << ", right = " << right << endl;
		return left;
    }
};

int main()
{
	Solution solu;
	cout << solu.arrangeCoins(12) << endl; // 5
	return 0;
}