// compare version numbers
//e.g.: 0.1 < 1.1 < 1.2 < 13.37
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int len1 = version1.size(), len2 = version2.size();
        int num1 = 0, num2 = 0;
        while(i < len1 || j < len2)
        {
            while(i < len1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                ++i;
            }
            while(j < len2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = 0, num2 = 0;
            ++i;
            ++j;
        }
        return 0;
    }
};

int main()
{
    Solution solu;
    cout << solu.compareVersion("0.1", "0.0.1") << endl;
    return 0;
}
