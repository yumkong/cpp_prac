#include <iostream>
#include <cstring> // memset
#include <algorithm> // sort
using namespace std;

bool isAnagram(const string &s1, const string &s2)
{
    if(s1.length() != s2.length()) return false;
    int len = s1.length();
    if(len == 1) return (s1 == s2);
    int count_tbl[256];
    memset(count_tbl, 0, sizeof(count_tbl));
    // first create table with str1
    int idx = 0, i = 0;
    for(i = 0; i < len; ++i)
    {
        idx = (int)s1[i];
        ++count_tbl[idx];
    }
    // then subtrating counts from table with str2
    // when less than 0, false; otherwise, true 
    for(i = 0; i < len; ++i)
    {
        idx = (int)s2[i];
        if(count_tbl[idx] == 0)
        {
            break; //break for loop
        }
        else
        {
            --count_tbl[idx];
        }
    }
    return (i == len); 
}
// borrowed from Hawstein
bool isAnagram2(string s1, string s2)
{
    if(s1.length() != s2.length()) return false;
    int len = s1.length();
    if(len == 1) return (s1 == s2);
    // sort string1 and 2 in place (ascending order), then compare
    // (use string::iterator)
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}

int main()
{
    string str1("ti ghtw");
    string str2("git wht");
    string str3("yuguang");
    cout << str1 << " and " << str2 << " ==> " << isAnagram2(str1, str2) << endl;
    cout << str1 << " and " << str3 << " ==> " << isAnagram2(str1, str3) << endl;
    return 0;
}
