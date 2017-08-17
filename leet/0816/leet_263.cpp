// ugly numbers are positive numbers whose prime factors only include 2,3,5. E.g. 6, 8
// 1 is typically treated as an ugly number.
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num > 1)
        {
            if(num % 5 == 0) num /= 5;
            else if(num % 3 == 0) num /= 3;
            else if(num % 2 == 0) num /= 2;
            else return false;
        }
        return (num == 1);
    }
};

int main()
{
    Solution solu;
    cout << solu.isUgly(89) << endl;
    return 0;
}
