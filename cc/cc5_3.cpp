// given an integer, print the next smallest and next largest number that have the same number
// of "1" bits in their binary representation
#include <iostream>
using namespace std;

int count_one(int x)
{
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}

int next(int x)
{
    int max_int = ~(1<<31);
    // how many "1" in x
    int num = count_one(x);
    // for 000...000, and 111...111 (-1), there is no bigger number with same number of "1" bits
    // so return -1 => no such integer
    if(num == 0 || x == -1) return -1;
    for(++x; count_one(x) != num && x < max_int; ++x);
    if(count_one(x) == num) return x;
    return -1; //if not find such integer, return -1
}

int previous(int x)
{
    // This is the minimal int (-2147483648)
    int min_int = (1<<31); 
    int num = count_one(x);
    // as indicated above, these two int also have no smaller number with the same of "1" bits
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x > min_int; --x);
    if(count_one(x) == num) return x;
    return -1;
}

int main()
{
    int a = 26;
    cout << previous(a) << " " << next(a) << endl;
    return 0;
}
