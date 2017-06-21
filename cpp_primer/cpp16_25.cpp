// this file answers both 16.24 and 16.25 
#include <iostream>
#include <string>
using namespace std;

// greater compare: return >0 when arg1 > arg2
template <typename T>
int compare(const T &a, const T &b)
{
    if(a < b) return -1;
    if(b < a) return 1;
    return 0;
}

int main()
{
    short sval = 123;
    int ival = 1023;
    // method1: use data type casting
    cout << compare(static_cast<int>(sval), ival) << endl;
    cout << compare(sval, static_cast<short>(ival)) << endl;
    // use explicit template arguments
    // compare<T>(arg1, arg2)==> cast both arg1 and arg2 to type T
    cout << compare<short>(sval, ival) << endl;
    cout << compare<int>(sval, ival) << endl;

    //compare two literal char strings
    // NOTE directly use "compare("Mary", "Anne")" is wrong because arg1 is char[5] and arg2 [6]
    cout << compare<string>("Mary", "David") << endl;
    cout << compare<string>("Mary", "Anna") << endl;
    // this is compiled ok since both args are char[5]
    // BUT the result is wrong==> it compares the first address of two arrays!!!
    cout << compare("Mary", "TAnn") << endl;
    return 0;
}
