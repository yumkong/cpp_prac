// given a string representing a student's attendance record, 'A' , 'L', 'P'
// a student is ok if <=1 'A' and <=2 continous 'L'. Check whether the student is ok
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int len = s.size();
        int Anum = 0, Lcontnum = 0;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == 'L') ++Lcontnum;
            else
            {
                Lcontnum = 0; 
                if(s[i] == 'A') ++Anum;
            }
            if(Lcontnum >= 3 || Anum > 1) return false;
        }
        return true;
    }
};

int main()
{
    Solution solu;
    cout << solu.checkRecord("PPALLP") << endl;
    cout << solu.checkRecord("PPALLL") << endl;
    return 0;
}
