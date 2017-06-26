//0625: THIS file cannot reach desired goal for the number randomly generated may be duplicated
// instead: USE cc12_3_add2.cpp
// based on cc12_3: what if you have only 10 MB of memory?
// 10 MB = 10 * 2^20 * 8 bits
#include <iostream>
#include <cstdio>
//#include <map>
//#include <utility> // pair
using namespace std;

typedef unsigned int uint;
//liu added
//typedef pair<int, int> pii;

int main()
{
    freopen("cc12_3.in", "r", stdin); // 2^32 integers
    uint int_len = sizeof(int) * 8; // 32 = 2^5
    uint totalnum = ~0; // 4G integers 2^32 - 1
    uint blocksize = (1 << 18); //2^18 == 256k
    uint blocknum = totalnum / blocksize + 1; // how many blocks needed => 2^14 = 16k 
    
    uint *block = new uint[blocknum]; //16k int => 64 kB 
    uint *bit = new uint[blocksize / int_len]; //2^15 = 32k int => 128 kB
    // added by liu
    // <block_idx, block_inner_idx>, cnt
    //map<pii, int> block_cnt; // 256k * 12 byte = 3MB
    int v;
    while(cin >> v)
    {
        //int blk_idx = v / blocksize, inner_idx = v % blocksize;
        //ppi tmp(blk_idx, inner_idx);
        // if 1st time 1, 2nd time 2, ...
        //++block_cnt[tmp]; 
        // how many integers fall into a certain block
        ++block[v / blocksize]; // this only applies when each number appear only once in file
    }
    fclose(stdin);
    
    uint start;
    for(uint i = 0; i < blocknum; ++i)
    {
        // there must be an integer missing in this block
        //debug
        cout << "i = " << i << " : " << endl;
        cout << block[i] << ", " << blocksize << endl;
        if(block[i] < blocksize)
        {
            start = i * blocksize;
            cout << "break at i = " << i << endl;
            break;
        }
    }
   
    freopen("cc12_3.in", "r", stdin);
    while(cin >> v)
    {
        // [0, blocksize), [blocksize, 2*blocksize), ...
        if(v >= start && v < start + blocksize)
        {
            v -= start; // remainent part in that block
            bit[v / int_len] |= (1 << (v % int_len));
        }
    }
    bool found = false;
    uint find_val = 0;
    for(uint i = 0; i < blocksize / int_len; ++i)
    {
        for(uint j = 0; j < int_len; ++j)
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
    //cout << "start = " << start << endl;
    //cout << "blocknum = " << blocknum << endl;
    cout << "The smallest value that not contain in file is " << find_val << endl;
    delete [] block;
    delete [] bit;
    fclose(stdin);
    return 0;
}
