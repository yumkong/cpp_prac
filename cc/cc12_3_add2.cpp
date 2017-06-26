// based on cc12_3: what if you have only 10 MB of memory?
// 10 MB = 10 * 2^20 * 8 bits
#include <iostream>
#include <cstdio>  // stdin
#include <cstring> // memset
//#include <map>
//#include <utility> // pair
using namespace std;

typedef unsigned int uint;
//liu added
//typedef pair<int, int> pii;

int main()
{
    freopen("cc12_3.in", "r", stdin); // 2^32 integers
    int int_len = sizeof(int) * 8; // 32 = 2^5
    int totalnum = ~(1 << 31); // 2G integers 2^31 - 1 => here we only consider positive int
    int blocksize = (1 << 26); //2^26 == 64M
    // how many blocks needed => 2^5 = 32 => so only need to have a big outer loop of 32 iterations
    int blocknum = totalnum / blocksize + 1;
    
    //uint *block = new uint[blocknum]; //16k int => 64 kB 
    uint *bit = new uint[blocksize / int_len]; //2^21 = 2M int => 8 MB
    // added by liu
    uint start; // starting number of this range
    int v; // hold input value
    bool found = false;
    uint find_val = 0;
    // big loop, altogether 32 iterations
    for(uint i = 0; i < blocknum; ++i)
    {
        start = i * blocksize;
        uint *bit = new uint[blocksize / int_len]; 
        // 3rd param: number of byte to be set
        memset(bit, 0, blocksize / int_len * sizeof(uint));
        freopen("cc12_3.in", "r", stdin);
        while(cin >> v)
        {
            // 
            if(v >= start && v < start + blocksize)
            {
                v -= start;
                bit[v / int_len] |= (1 <<(v % int_len));
            }
        }
        // find if there is empty bit in this block
        //bool found = false;
        //uint find_val = 0;
        for(int i = 0; i < blocksize / int_len; ++i)
        {
            for(int j = 0; j < int_len; ++j)
            {
                if((bit[i] & (1 << j)) == 0)
                {
                    find_val =  i * int_len + j + start;
                    found = true;
                    break;
                } 
            }
            if(found) break;
        }

        delete [] bit;
        fclose(stdin);
        if(found) break;
    }
   
    //cout << "start = " << start << endl;
    //cout << "blocknum = " << blocknum << endl;
    if(found)
    {
        cout << "The smallest value that not contain in file is " << find_val << endl;
    }
    else
    {
        cout << "No such value found!" << endl;
    }
    return 0;
}
