// print the last K lines of an input file using C++
#include <iostream>
#include <fstream>
using namespace std;

void printLastKLines(ifstream &fin, int k)
{
    // only use k lines to save space
    string line[k];
    int lines = 0;
    string tmp;
    // use fstream to get a line of code
    while(getline(fin, tmp))
    {
        line[lines % k] = tmp;
        ++lines;
    }
    int start, cnt;
    if(lines < k)
    {
        start = 0;
        cnt = lines;
    }
    else
    {
        start = lines % k;
        cnt = k;
    }
    for(int i = 0; i < cnt; ++i)
    {
        cout << line[(start + i) % k] << endl;
    }
}

int main()
{
    ifstream fin("cc13_1.in");
    int k = 4;
    printLastKLines(fin, k);
    fin.close(); 
    return 0;
}
