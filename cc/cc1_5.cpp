#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string s, string reps)
{
    if (s.length() == 0) return s;
    int len = s.length();
    string newstr("");
    for(int i = 0; i < len; ++i)
    {
        if(s[i] == ' ')
        {
            newstr += reps;
        }
        else
        {
            newstr += s[i]; 
        }
    }
    return newstr;
}

int main()
{
   string oldstr("I am likely to go Que");
   string reps("%20");
   cout << "Old: " << oldstr << endl;
   cout << "New: " << replaceSpaces(oldstr, reps) << endl;
}
