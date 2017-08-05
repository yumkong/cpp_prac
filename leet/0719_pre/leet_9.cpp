#include <iostream>
using namespace std;
// inspired by gaurav5's solution
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) return false;
        if(x < 10) return true; // single digit always true
        int reverse_x = 0;
        while(reverse_x < x)
        {
            reverse_x = reverse_x * 10 + (x % 10);
            x = x / 10;
        }
        // not the special case (10,20...) has been removed by first condition above
        return (x == reverse_x) || (x == reverse_x / 10); 
    }
};

int main()
{
    Solution solu;
    cout << solu.isPalindrome(12321) << endl;
    cout << solu.isPalindrome(1221) << endl;
    cout << solu.isPalindrome(1223) << endl;
    return 0;
}
