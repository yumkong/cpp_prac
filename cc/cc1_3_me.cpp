// remove duplicate characters in a string. Not use any additional buffer
#include <iostream>
#include <cstring>
using namespace std;

// string -> NoneType
// update string on-site
void removeDuplicates(string &s)
{
    int len = s.length();
    if(len < 2) return;
 
    bool a[256];
    memset(a, 0, sizeof(a));
 
    int tail = 0; // but the 1st is always false
    for(int i = 0; i < len; ++i)
    {
        int v = (int)s[i];
        // if first seen
        if(!a[v])
        {
            if(tail != i)
            {
                s[tail++] = s[i];
            }
            else
            {
                tail++;
            }       
            a[v] = true;
        }
    }
    s = s.substr(0, tail);
    //cout << "tail = " << tail << endl;
}

int main()
{
    // string not contain any duplicates
    string s1 = "abcdefgh";
    // string contains all duplicates
    string s2 = "aaaaaa";
    // Null string
    string s3 = "";
    // string with all continuous duplicates
    string s4 = "aaabbb";
    // string with non-contiguous duplicate
    string s5 = "ababababa";
    cout << s1 << " ==> ";
    removeDuplicates(s1);
    cout << s1 << endl;
    
    cout << s2 << " ==> ";
    removeDuplicates(s2);
    cout << s2 << endl;
    
    cout << s3 << " ==> ";
    removeDuplicates(s3);
    cout << s3 << endl;

    cout << s4 << " ==> ";
    removeDuplicates(s4);
    cout << s4 << endl;

    cout << s5 << " ==> ";
    removeDuplicates(s5);
    cout << s5 << endl;
}
