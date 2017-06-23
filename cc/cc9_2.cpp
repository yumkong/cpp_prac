// sort an array of strings so that all the anagrams are next to each other
// anagram: two words has the same length and same number of each characters
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// not using reference => only impact parameters not arguments
bool cmp(string s1, string s2)
{  
    //sort(iterator first, iterator last) ==> sort [first, last) into ascending order (operator<)
    //sort(iterator first, iterator last, comp) ==> sort [first, last) according to comp
    // ==> in other word, make comp(a[i], a[i+1]) true, for all i's
    sort(&s1[0], &s1[0] + s1.length());
    sort(&s2[0], &s2[0] + s2.length());
    return s1 < s2;
}

int main()
{
    string s[] = {"axyz", "abc", "yzax", "bac", "zyxa", "bca", "fg", "gf"};
    sort(s, s + 8, cmp);
    for(int i = 0; i < 8; ++i)
    {
        cout << s[i] << endl;
    }
    return 0;
}
