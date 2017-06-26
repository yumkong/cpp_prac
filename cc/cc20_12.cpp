//given an N x N matrix of positive and negative integers, find the sub-matrix with the largest possible sum
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 100;
int p[MAX_N][MAX_N], A[MAX_N][MAX_N];

// this is to compute the integral image
void preCompute(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        p[0][i] = p[i][0] = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            // p[i][j] => contains sum of the submatrix [0: i, 0: j]
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i-1][j-1] + A[i][j];
        }
    }
}

int maxSum(int n)
{
    int max_sum = 1 << 31; // min_int
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int cur_sum = 0;
            for(int k = 1; k <= n; ++k)
            {   
                // sum of [i:j, k] ==> a column if integers: has j-i+1 elements
                int val = p[j][k] - p[j][k-1] - p[i-1][k] + p[i-1][k-1];
                if(cur_sum <= 0) cur_sum = val;
                else cur_sum += val;
                
                if(cur_sum > max_sum) max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    freopen("cc20_12.in", "r", stdin);
    int n;
    cin >> n; // size of matrix
    // elems saved from 1
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> A[i][j];
        }
    }
    preCompute(n);
    cout << maxSum(n) << endl;
    fclose(stdin);
   
    return 0;
}
