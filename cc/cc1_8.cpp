//given s1, s2 check if s2 is a rotation of s1 using one call of isSubstring
#include <iostream>
#include <string>
using namespace std;

//check if str2 is a substring of str1
bool isSubstring(const string &str1, const string &str2)
{
    size_t found = str1.find(str2);// return string::npos if no matches found
    return (found != string::npos); 
}

bool checkRotation(const string &s1, const string &s2)
{
    if(s1.length() != s2.length()) return false;
    return isSubstring(s1+s1, s2);
}

int main()
{
    string s1("waterbottle");
    string s2("erbottlewat");
    string s3("tightwaters");
    cout << s1 << " and " << s2 << " => " << checkRotation(s1, s2) << endl;
    cout << s1 << " and " << s3 << " => " << checkRotation(s1, s3) << endl;
    return 0;
}
