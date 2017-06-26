//given a string S and an array of smaller strings T, design a method to search for each in T
#include <iostream>
#include <cstring> // memset
using namespace std;

class Trie
{
public:
    static const int MAX_N = 100 * 100; // 100 is length of main string
    static const int CLD_NUM = 26;
    int size;
    int trie[MAX_N][CLD_NUM];
    
    Trie(const char* s);
    void insert(const char *s);
    bool find(const char *s);
};

Trie::Trie(const char *s) // mississippi
{
    // initialize the first row as  -1
    memset(trie[0], -1, sizeof(trie[0]));
    size = 1; 
    while(*s)
    {
        insert(s);
        ++s; // rebuild the tree starting from the second char
    }
}

// create a suffix tree for s
// e.g. for word "bibs"
// bibs -- b - i - b - s
//         | - s
//      -- i - b - s
//      -- s             
void Trie::insert(const char *s)
{
    int p = 0;
    while(*s)
    {
        // 'a': 97, 'A': 65
        int i = *s - 'a';   // 'm'-'a' = 12, 'i'-'a' = 8, ..= 18
        // this int is not occupied
        if(-1 == trie[p][i]) //[0][12] == -1, [1][8] == -1, [2][18] == -1
        {
            memset(trie[size], -1, sizeof(trie[size]));//init trie[1], init trie[2], init trie[3]
            trie[p][i] = size++; // trie[0][12] = 1, size = 2;   trie[1][8] = 2, size = 3;
            // trie[2][18] = 3, size = 4
        }
        // tree's leaf points to the next row idx
        p = trie[p][i]; // p = 1, p = 2
        ++s;  // go to next char, .., 
    }
}

bool Trie::find(const char* s)
{
    int p = 0;
    while(*s)
    {
        int i = *s - 'a';
        if(-1 == trie[p][i]) return false;
        p = trie[p][i];
        ++s;
    }
    return true;
}

int main()
{
    Trie tree("mississippi");
    string partt[] = {"is","sip","hi","sis","mississippa"};
    int n = 5;
    for(int i = 0; i < n; ++i)
    {
        cout << tree.find((char*)&partt[i][0]) << endl;
    }
    return 0;
}
