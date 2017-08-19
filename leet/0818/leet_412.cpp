// output the string representation of numbers from 1 to n
// for 3x (multiples of three) return Fizz. for 5x (mulitple of five) return Buzz, for both "FizzBuzz"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; ++i)
        {
            if(i % 3 != 0 && i % 5 != 0) res.push_back(to_string(i));
            else 
            {
                if(i % 3 == 0)
                {
                    if(i % 5 == 0) res.push_back("FizzBuzz");
                    else res.push_back("Fizz");
                }
                else res.push_back("Buzz");
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<string> res = solu.fizzBuzz(15);
    for(auto &s: res) cout << s << endl; 
    return 0;
}
