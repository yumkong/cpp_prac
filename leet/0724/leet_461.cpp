// compute the hamming distance of two non-negative integers
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x == 0 && y == 0) return 0;
        int dist = 0;
        int z = x ^ y;
        while(z > 0)
        {
            if(z & 0x01 == 1) ++dist;
            z >>= 1;
        }
        return dist;
    }
};

int main()
{
    Solution solu;
    cout << solu.hammingDistance(1, 2) << endl;
    return 0;
}
