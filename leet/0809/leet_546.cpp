//remove boxes 
// definition of the subproblem is not self-contained and its solution relies on information external to the subproblem itself
// solver: modify the definition of the problem to absorb the external information so that the new one is self-contained.
// Define T(i, j) as the maximum points one can get by removing boxes of the subarray boxes[i, j] (both inclusive). The original problem is identified as T(0, n - 1) and the termination condition is as follows:
//T(i, i - 1) = 0: no boxes so no points.
//T(i, i) = 1: only one box left so the maximum point is 1
//redefine T(i, j) to make it self-contained. First let's identify the external information. On the one hand, from the point of view of the subarray boxes[m, j], it knows nothing about the number (denoted by k) of boxes of the same color as boxes[m]to its left. On the other hand, given this number k, the maximum points can be obtained from removing all these boxes is fixed. Therefore the external information to T(i, j) is this k. Next let's absorb this extra piece of information into the definition of T(i, j) and redefine it as T(i, j, k) which denotes the maximum points possible by removing the boxes of subarray boxes[i, j] with k boxes attached to its left of the same color as boxes[i]. Lastly let's reexamine some of the statements above:
//Our original problem now becomes T(0, n - 1, 0), since there is no boxes attached to the left of the input array at the beginning.
//The termination conditions now will be:
//a. T(i, i - 1, k) = 0: no boxes so no points, and this is true for any k (you can interpret it as nowhere to attach the boxes).
//b. T(i, i, k) = (k + 1) * (k + 1): only one box left in the subarray but we've already got k boxes of the same color attached to its left, so the total number of boxes of the same color is (k + 1) and the maximum point is (k + 1) * (k + 1).
//The recurrence relation is as follows and the maximum points will be the larger of the two cases:
//a. If we remove boxes[i] first, we get (k + 1) * (k + 1) + T(i + 1, j, 0) points, where for the first term, instead of 1 we again get (k + 1) * (k + 1) points for removing boxes[i] due to the attached boxes to its left; and for the second term there will be no attached boxes so we have the 0 in this term.
//b. If we decide to attach boxes[i] to some other box of the same color, say boxes[m], then from our analyses above, the total points will be T(i + 1, m - 1, 0) + T(m, j, k + 1), where for the first term, since there is no attached boxes for subarray boxes[i + 1, m - 1], we have k = 0 for this part; while for the second term, the total number of attached boxes for subarray boxes[m, j] will increase by 1 because apart from the original k boxes, we have to account for boxes[i]now, so we have k + 1 for this term. But we are not done yet. What if there are multiple boxes of the same color as boxes[i]? We have to try each of them and choose the one that yields the maximum points. Therefore the final answer for this case will be: max(T(i + 1, m - 1, 0) + T(m, j, k + 1)) where i < m <= j && boxes[i] == boxes[m].
//Before we get to the actual code, it's not hard to discover that there is overlapping among the subproblems T(i, j, k), therefore it's qualified as a DP problem and its intermediate results should be cached for future lookup. Here each subproblem is characterized by three integers (i, j, k), all of which are bounded, i.e, 0 <= i, j, k < n, so a three-dimensional array (n by n by n) will be good enough for the cache.
#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
		// using this will Time Limit Exceeded => change to array
		//vector<vector<vector<int> > > dp(len, vector<vector<int> >(len, vector<int>(len, 0)));
		int ***dp = new int**[len];
		for(int i = 0; i < len; ++i)
		{
			dp[i] = new int*[len];
			for(int j = 0; j < len; ++j)
			{
				dp[i][j] = new int[len];
				memset(dp[i][j], 0, len * sizeof(int)); // (start pointer, value, #bytes)
			}
		}
		//int dp[100][100][100] = {0};
		return helper(boxes, dp, 0, len - 1, 0);
    }
	//int helper(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int> > >& dp)
	int helper(vector<int>& boxes, int ***dp, int i, int j, int k)
	//int helper(vector<int>& boxes, int dp[100][100][100], int i, int j, int k)
	{
		if(i > j) return 0;
		if(dp[i][j][k] > 0) return dp[i][j][k]; // memorization
		//IMPORTANT for improve efficiency
		while(j > i && boxes[j] == boxes[j - 1]) {--j; ++k; }
		int res = (k + 1) * (k + 1) + helper(boxes, dp, i, j-1, 0);
		for(int m = i; m < j; ++m)
		{
			if(boxes[m] == boxes[j])
				res = max(res, helper(boxes, dp, i, m, k+1) + helper(boxes, dp, m+1, j-1, 0));
		}
		dp[i][j][k] = res;
		return res;
	}
};

int main()
{
	vector<int> input({1, 3, 2, 2, 2, 3, 4, 3, 1});
	Solution solu;
	cout << solu.removeBoxes(input) << endl;
	return 0;
}







