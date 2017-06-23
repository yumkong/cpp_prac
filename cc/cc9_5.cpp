//given a sorted array of strings which is interspersed with empty strings, find the location of a given string
#include <iostream>
using namespace std;

template <int N>
int findLoc(string (&ss)[N], string squery)
{ 
    // first and last index of ss
    int low = 0, high = N - 1;
    if(squery == "") return -1;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        int t = mid;
        while(ss[t] == "" && t <= high) ++t;
        if(t > high) high = mid - 1;
        else
        {
            if(ss[t] == squery) return t;
            else if(ss[t] < squery) low = t + 1;
            else high = mid - 1;
        } 
    }
    return -1;
}

int main()
{
    string ss[] = {"abs", "", "",  "batch", "concat", "deduce", "howmany", "minus", "negate", "remain"};
    int loc = findLoc(ss, "howmany"); // 6
    cout << loc << endl;
    return 0;
}
