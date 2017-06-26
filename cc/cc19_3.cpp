// compute number of trailing zeros in n fractorial
// => how many pairs of (2, 5)
#include <iostream>
using namespace std;

int count_n_nums(int x, int n)
{
    //if(n == 0) return 0;
    int cnt = 0;
    while(x >= n && x % n == 0)
    {
        ++cnt;
        x /= n;
    }
    return cnt;
}

int find_trail_zero(int n)
{
    int cnt_two = 0;
    int cnt_five = 0;
    if(n < 2) return 0;
    for(int i = 2; i <= n; ++i)
    {
        cnt_two += count_n_nums(i, 2);
        cnt_five += count_n_nums(i, 5);
    }
    //cout << "2 has " << cnt_two << endl;
    //cout << "5 has " << cnt_five << endl;
    return min(cnt_two, cnt_five);
}

int main()
{
    for(int n = 1; n < 100; ++n)
    {
        cout << n << "! has " << find_trail_zero(n) << " trailing zeros" << endl;
    }
    return 0;
}
