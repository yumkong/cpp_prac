// implement rand7() using rand5()
#include <iostream>
#include <cstdlib> // rand()
using namespace std;

int rand5()
{
    return rand() % 5 + 1;
}

int rand7()
{
    while(true)
    {
        // this will generate 0~24 with uniform distribution
        int num = 5 * (rand5() - 1) + (rand5() - 1);
        // uniformly generate 0~6 + 1
        if(num < 21) return (num % 7 + 1); 
    }
}

int main()
{
    srand((unsigned)time(0));
    for(int i = 0; i < 20; ++i) 
    {
        cout << rand7() << endl;
    }
    return 0;
}
