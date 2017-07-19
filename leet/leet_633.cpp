#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
	int mid = (int)sqrt(c);
	bool found = false;
	for(int i = mid; i >= 0; --i)
	{
	    if(isSquareNum(c - i * i)) // find x^2
	    {
		found = true;
		break;
	    }
	}
	return found;
    }
    bool isSquareNum(int n)
    {
        int tmp = (int)sqrt(n);
        return (n == tmp * tmp);
    }
};

int main()
{
    Solution solu;
    cout << solu.judgeSquareSum(0) << endl;
    return 0;
}
