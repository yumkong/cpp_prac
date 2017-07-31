// this can check how an int is presented in binary
#include <iostream>
#include <vector>
#include <cstdlib> // rand()
using namespace std;

void print_binary(int src)
{
    vector<int> v;
    int len = 8 * sizeof(int);
    int mask = 1;
    // *** the following operation is like stack
    // save from lower bit to higher bit
    while(len--)
    {
        if(src & mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    // print from higher bit to lower bit
    while(!v.empty())
    {
        cout << v.back();
        v.pop_back();
    }
    //cout << endl;
}

int main()
{
    int a = (1<<31); //1000..0000
    int b = a + 1; // 1000..0001
    print_binary(-1);
    cout << " => " << -1 << endl;
    print_binary(a);
    cout << " => " << a << endl;
    print_binary(b);
    cout << " => " << b << endl;

    cout << "-7/2 = " << (-7)/2 << endl;
    cout << "-7/3 = " << (-7)/3 << endl; 

    //int val;
    //while(cin >> val)// cin will not quit when reading 0, only ctrl_c can let it quit
    //{
    //    cout << val << endl;
    //}
    cout << RAND_MAX << endl;
    return 0;
}
