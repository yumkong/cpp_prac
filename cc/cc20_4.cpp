// count the number of 2's between 0 and n
#include <iostream>
using namespace std;

int count2(int n)
{
    int cnt = 0;
    while(n > 0)
    {
        if(n % 10 == 2) ++cnt;
        n /= 10;
    }
    return cnt;
}

int main()
{
    int accum_cnt = 0;
    for(int i = 0; i < 101; ++i)
    {
        accum_cnt += count2(i);
        cout << accum_cnt << endl;
    }
    return 0;
}
