#include <iostream>
#include <cstring>
using namespace std;

bool isUnique1(string s)
{
    // use bool (binary value) to only record if it has appeared before
    bool a[256];
    //liu: set the first sizeof(a) bytes of the memory block pointed by a to 0
    // here each bool represents 1 byte
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int v = (int)s[i];
        if(a[v]) 
        {
            return false;
        }
        a[v] = true;
    }
    // if come here, all chars are passed 
    return true;
}

bool isUnique2(string s)
{
    // 1 int is 32 bit, 8 ints are 256 bits --> covering all chars
    int a[8];
    // initial all 32 bytes in this array as 0
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int v = (int)s[i];
        // which int array unit to go
        // which bit of this unit to go
        int idx = v / 32, shift = v % 32;
        // great bit manipulation!!!
        if(a[idx] & (1 << shift))
        {
            return false;
        }
        a[idx] |= (1 << shift);
    }
    return true;
}

int main()
{
    string s1 = "i am yuguang";
    string s2 = "ab#$S@cdefghijklmnopqrstuvwxyz";
    cout << "isUnique1(" << s1 << "): " << isUnique1(s1) << endl;
    cout << "isUnique2(" << s2 << "): " << isUnique2(s2) << endl;
    return 0;
}
