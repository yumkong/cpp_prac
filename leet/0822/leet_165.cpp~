// compare version numbers
//e.g.: 0.1 < 1.1 < 1.2 < 13.37
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = version1.find('.');
        int pos2 = version2.find('.');
        int len1 = version1.size(), len2 = version2.size();
        string intpart1 = version1.substr(0, pos1);
        string decipart1("");
        if((string::size_type)pos1 != string::npos) decipart1 = version1.substr(pos1 + 1, len1 - pos1);
        while(intpart1.size() >= 1 && intpart1[0] == '0') intpart1.erase(0,1);
        while(decipart1.size() >= 1 && decipart1[0] == '0') decipart1.erase(0,1);
        string intpart2 = version2.substr(0, pos2);
        string decipart2("");
        if((string::size_type)pos2 != string::npos) decipart2 = version2.substr(pos2 + 1, len2 - pos2);
        while(intpart2.size() >= 1 && intpart2[0] == '0') intpart2.erase(0,1);
        while(decipart2.size() >= 1 && decipart2[0] == '0') decipart2.erase(0,1);

        cout << "int1 = " << intpart1 << endl;
        cout << "deci1 = " << decipart1 << endl;
        cout << "int2 = " << intpart2 << endl;
        cout << "deci2 = " << decipart2 << endl;
        if(intpart1.size() > intpart2.size()) return 1;
        else if(intpart1.size() < intpart2.size()) return -1;
        else
        {
            if(intpart1 > intpart2) return 1;
            else if(intpart1 < intpart2) return -1;
            else
            {   // length of decimal part
                if(decipart1.size() > decipart2.size()) return 1;
                else if(decipart1.size() < decipart2.size()) return -1;
                else
                {
                    if(decipart1 > decipart2) return 1;
                    else if(decipart1 < decipart2) return -1;
                    else return 0;
                }
            }
        }
    }
};

int main()
{
    Solution solu;
    cout << solu.compareVersion("0.1", "0.0.1") << endl;
    return 0;
}
