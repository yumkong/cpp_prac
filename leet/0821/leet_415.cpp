// adding strings
// given two non-negative integers represented as string, return the sum of them
// NOTE: must not use any built-in BigInteger library or convert the inputs to integer directly.
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int len1 = num1.size(), len2 = num2.size(), advance = 0, sum = 0;
        while(len1 >= 1 && len2 >= 1)
        {
            sum = (num1[len1 - 1] - '0') +  (num2[len2 - 1] - '0') + advance;
            res.insert(0, to_string(sum % 10));
            advance = sum / 10;
            --len1; 
            --len2;
        }
        while(len1 >= 1)
        {
            sum = (num1[len1 - 1] - '0') + advance;
            res.insert(0, to_string(sum % 10));
            advance = sum / 10;
            --len1;
            if(advance == 0 && len1 >= 1) 
            {
                res.insert(res.begin(), num1.begin(), num1.begin() + len1);
                break;
            }
        }
        while(len2 >= 1)
        {
            sum = (num2[len2 - 1] - '0') + advance;
            res.insert(0, to_string(sum % 10));
            advance = sum / 10;
            --len2;
            if(advance == 0 && len2 >= 1) 
            {
                res.insert(res.begin(), num2.begin(), num2.begin() + len2);
                break;
            }
        }
        if(advance == 1) res = "1" + res;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.addStrings("6534321234566", "5432356") << endl; // 6666922
    return 0;
}
