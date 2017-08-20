// category: brainteaser
// nim game :  can always win a Nim game if the number of stones nn in the pile is not divisible by 4.
#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);        
    }
};

int main()
{
    Solution solu;
    cout << solu.canWinNim(4) << endl;
    return 0;
}
