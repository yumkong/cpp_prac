// count the number of prime numbers less than a non-negative number n
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // below is my answer: TLE
    /*
    int countPrimes(int n) {
        if(n <= 2) return 0;
        if(n == 3) return 1; // 2 < 3
        if(n == 4) return 2; // 2 3 < 4
        int cnt = 2;
        for(int i = 5; i < n; i += 2)
        {
            if(isPrime(i)) ++cnt;
        }
        return cnt;
    }
    bool isPrime(int n)
    {
        int mid = n / 2;
        for(int i = 2; i <= mid; ++i)
        {
            if(n % i == 0) return false;
        }
        return true;
    }*/
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int cnt = 0;
        for(int i = 2; i < n; ++i)
        {
            if(!notPrime[i])
            {
                ++cnt;
                for(int j = 2; j * i < n; ++j)
                    notPrime[i * j] = true;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solu;
    cout << solu.countPrimes(11) << endl;
    return 0;
}
