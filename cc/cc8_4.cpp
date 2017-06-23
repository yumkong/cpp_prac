#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;

vs permu1(string s)
{
    //cout << "come here" << endl;
    vs result;
    if(s == "") // empty str
    {
        result.push_back("");
        return result;
    }
    for(int i = 0; i < s.length(); ++i)
    {
        // note that string c has only 1 element
        // substr(i, j): start copying from the ith char and copy j char 
        string c = s.substr(i, 1); // separate each possible single char from the string, and recursive other parts
        string t = s;
        vs res = permu1(t.erase(i, 1)); //erase that selected char, save syntax as substr
        for(int j = 0; j < res.size(); ++j)
        {
            result.push_back(c + res[j]);
        }
    }
    //cout << "come here 666 " << endl;
    return result;
}

int main()
{
    string s = "abcde";
    vs res = permu1(s);
    cout << "result size = " << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
