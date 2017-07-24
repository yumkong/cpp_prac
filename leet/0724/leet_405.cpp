// convert a 32-bit integer to hexadecimal
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        bool sign = (num > 0) ? true : false; 
        string res;
        for(int i = 0; i < 32; i += 4)
        {
            int tmp = ((num & (0xf << i)) >> i);
            // deal with the 4 significant bits of negatives
            if(!sign && tmp < 0) tmp = 16 + tmp;
            res = getHexStr(tmp) + res;
            if(sign && (num >> (i+4)) == 0) break;
        }
        return res;
    }
    string getHexStr(int num)
    {
        if(num < 10) return to_string(num);
        else
        {
            string s(1, 'a' + num - 10);
            return s;
        }
    }
};

int main()
{
    Solution solu;
    cout << solu.toHex(26) << endl;
    cout << solu.toHex(2) << endl;
    cout << solu.toHex(1<<31) << endl;
    cout << solu.toHex(~(1<<31)) << endl;
    return 0;
}
