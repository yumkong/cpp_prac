// define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
// given an int n, check whether it is a perfect number
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false; // because "except itself"
        int sum = 1, upperbnd = (int)sqrt(num);
        for(int i = 2; i <= upperbnd; ++i)
        {
            if(num % i == 0)
            {
                sum += i;
                sum += num / i;
            }
        }
        return sum == num;
    }
};

int main()
{
    Solution solu;
    cout << solu.checkPerfectNumber(27) << endl;
    return 0;
}
