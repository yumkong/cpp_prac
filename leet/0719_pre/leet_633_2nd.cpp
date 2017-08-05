#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> sqrVec;
		int i = 0; //start from 0, 2^2 + 0^2 are also ok
        int	sqr = i * i;
		bool found = false;
		while(sqr <= c)
		{
			if(find(sqrVec.begin(), sqrVec.end(), sqr) != sqrVec.end() || c == 2*sqr) // find x^2
			{
				found = true;
				break;
			}
			else
			{
				sqrVec.push_back(c - sqr);
			}
			++i;
			sqr = i * i;
		}
		return found;
    }
};

int main()
{
	Solution solu;
	cout << solu.judgeSquareSum(2147482647) << endl;
	return 0;
}