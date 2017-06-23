//find the i-th integer whose only prime factors are 3, 5 and 7
#include <iostream>
#include <queue>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int mini(int a, int b, int c)
{
    return MIN(MIN(a, b), c);
}

int get_num(int k)
{
    if(k <= 0) return 0;
    int res = 1, cnt = 1;
    queue<int> q3, q5, q7;
    q3.push(3);
    q5.push(5);
    q7.push(7);
    for(; cnt < k; ++cnt)
    {
        int v3 = q3.front();  //3 9 9  
        int v5 = q5.front();  //5 5 15
        int v7 = q7.front();  //7 7 7
        res = mini(v3, v5, v7); // 3 5 7
        // 0623: there are so many trick!!! need to understand more and more
        if(res == v7)
        {
            q7.pop(); // 21 35
        }
        else
        {
            if(res == v5)
            {
                q5.pop(); // 15
            }
            else
            {
                if(res == v3)
                {
                    q3.pop();
                    q3.push(3 * res); // 9
                }
            }
            q5.push(5 * res); // 15 25
        }
        q7.push(7 * res); // 21 35 49
    }
    return res;
}

int main()
{
    for(int i = 1; i < 20; ++i)
    {    
        cout << get_num(i) << endl;
    }
    return 0;
}
