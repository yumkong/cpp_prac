// given any two words in a large text file containing words.
// find the shortest distance between them in terms of the number of words
// can you make the searching in O(1) time ?
// what is the space complexity ?
#include <iostream>
#include <string>
using namespace std;

const int kMaxInt = ~(1 << 31);

int shortestDist(string text[], int n, string word1, string word2)
{
    int minI = kMaxInt / 2;
    int pos1 = -minI;
    int pos2 = -minI;
    for(int pos = 0; pos < n; ++pos)
    {
        //NOTE: there is no order between word1 and word2, any of them can be at front
        if(text[pos] == word1)
        {
            pos1 = pos;
            int dist = pos1 - pos2;
            // if word2 not found yet, pos2 = -minI => dist > minI
            if(dist < minI)
            {
                minI = dist;
            }
        }
        else if(text[pos] == word2)
        {
            pos2 = pos;
            int dist = pos2 - pos1;
            // if word1 not found yet, pos1 = -minI => dist > minI
            if(dist < minI)
            {
                minI = dist;
            }
        }
    }
    return minI;
}


int main()
{
    string text[] = {"What", "is", "your", "name", "My", "name", "is", "yum"};
    int len = 8;
    cout << shortestDist(text, len, "is", "name") << endl;
    return 0;
} 
