// find the longest word made of the other words in a list of words
#include "cc20_7_hash.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

// an hash object
Hash hash;

// order them from long to short
inline bool cmp(string s1, string s2)
{
    return s1.length() > s2.length();
}

bool MakeOfWords(string word, int length)
{
    int len = word.length();
    if(len == 0) return true;
    for(int i = 1; i <= len; ++i)
    {
        // get the original str, aka. itself
        if(i == length) return false;
        string str = word.substr(0, i);
        if(hash.find((char *)&str[0]))
        {
            // continue find the word starting from i-th char 
            // *** this is a recursion ==> change to iteration later
            // substr(i)=> from the i-th char to the end of the string
            if(MakeOfWords(word.substr(i), length)) return true;
        }
    }
    return false;
}

void PrintLongestWord(string word[], int n)
{
    // At the beginning save all words to hashtable
    for(int i = 0; i < n; ++i)
    {
        // the word's char array's first char's address
        hash.insert((char *)&word[i][0]);
    }
    // sort so that always start from the longest
    sort(word, word + n, cmp);
    for(int i = 0; i < n; ++i)
    {
        if(MakeOfWords(word[i], word[i].length()))
        {
            cout << "Longest Word: " << word[i] << endl;
            return;
        }
    }
}


int main()
{
    string arr[] = {"test", "tester", "testertest", "testing", "apple", "seattle",
                    "banana", "batting", "ngcat", "batti", "bat", "testingtester",
                    "testbattingcat" };
    int len = 13;
    PrintLongestWord(arr, len);
    return 0;
}
