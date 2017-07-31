// plus one to the integer represented by a non-empty array of digits
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int incre = 0;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            digits[i] += 1;
            if(digits[i] < 10) 
            {
                incre = 0;
                break;
            }
            else
            {
                digits[i] = 0;
                incre = 1;
            }
        }
        if(incre == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    // 123456999 + 1
    int a[] = {1,2,3,4,5,6,9,9,9};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    vector<int> res = solu.plusOne(arr);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res.at(i);
    }
    cout << endl;
    return 0;
}
