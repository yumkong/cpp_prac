//given an input file with 4 G (4 billion) intergers, generate an integer which is not contained in the file
// assume has 1GB memory
#include <iostream>
#include <cstdio>
#include <cstdlib> // rand()
using namespace std;

void generate_int_file()
{
    srand((unsigned)time(0));
    freopen("cc12_3.in", "w", stdout);
    int miss = 666;
    unsigned int max_uint = ~0;
    //for(int i = 0; i < 200000; ++i)
    //{
    //    if(i == miss) i += 1;
    //    cout << i << endl;
    //}
    int val;
    for(unsigned int i = 1; i < max_uint; ++i)
    {
        val = rand();
        //if(val == miss) val += 1;
        cout << val << endl;
    }
    fclose(stdout);
}

int main()
{
    //generate_int_file();
    freopen("cc12_3.in", "r", stdin);
    // how many bits in one integer (each bit can hash 1 integer)
    int int_len = sizeof(int) * 8;
    // how many integers needed to hash 4G integers
    int bit_len = 0xffffffff / int_len;  
    int *bit = new int[bit_len + 1]; // need to +1? => yes, I think so => so that idx 0 ~ bit_len
    int v;
    while(cin >> v)
    {
        //cout << v << endl;//for debug
        // put 1 to the particular integer's particular bit
        bit[v / int_len] |= (1 << (v % int_len));
    }
    bool found = false;
    int val = 0;
    for(int i = 0; i < bit_len; ++i)
    {
        for(int j = 0; j < int_len; ++j)
        {
            //NOTE bit[i] is an integer!!!
            if((bit[i] & (1 << j)) == 0) //never hashed
            {
                //cout << i * int_len + j << endl;
                val = i * int_len + j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(found) cout << "the smallest value that not contain in file is " << val << endl;
    delete [] bit;
    fclose(stdin);
    return 0; 
}

