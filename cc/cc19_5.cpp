#include <iostream>
#include <cstring>
using namespace std;

struct Result
{
    int hits;
    int pseudo_hits;
};

int Min(int a, int b)
{
    return a < b? a: b;
}

Result Estimate(const char* resolution, const char* guess)
{
    Result res;
    res.hits = 0;
    res.pseudo_hits = 0;
     
    int num = 26 + 5; // why? 
    int guess_count[num], solution_count[num]; 
    memset(guess_count, 0, sizeof(guess_count));
    memset(solution_count, 0, sizeof(solution_count));
    for(int i = 0; i < 4; ++i)
    {
        if(guess[i] == resolution[i]) ++res.hits;
        ++guess_count[(int)(guess[i]- 'A')];
        ++solution_count[(int)(resolution[i] - 'A')];
    }
    char color[] = "RGBY";
    for(int i = 0; i < 4; ++i)
    {
        int idx = (int)(color[i] - 'A');
        res.pseudo_hits += Min(guess_count[idx], solution_count[idx]);
    }
    res.pseudo_hits -= res.hits;
    return res;
}

int main()
{
    char solution[] = "RYGB";
    char guess[] = "YRRR";
    Result res = Estimate(solution, guess);
    cout << res.hits << " " << res.pseudo_hits << endl;
    return 0;
}
