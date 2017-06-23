#include "cpp16_52_count.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    double da[] = {2.1, 2.2, 2.3, 2.4, 2.3, 2.8};
    double dsa[] = {2.3, 2.4};
    int ia[] = {1,2,3,4,5,6,7,8,9,2};
    int isa[] = {2, 10};
    char ca[] = {'a','b','o','a','r','d','w','d'};
    char csa[] = {'a','b'};
    string sa[] = {"many", "much", "good", "bad", "large", "small"};
    string ssa[] = {"many", "small", "good"};
    vector<double> dvec(da, da + 6);
    vector<double> dsought(dsa, dsa + 2);
    vector<int> ivec(ia, ia + 10);
    vector<int> isought(isa, isa + 2);
    vector<char> cvec(ca, ca + 8);
    vector<char> csought(csa, csa + 2);
    vector<string> svec(sa, sa + 6);
    vector<string> ssought(ssa, ssa + 3);

    cout << "double vec: " << count(dvec, dsought) << endl;
    cout << "int vec: " << count(ivec, isought) << endl;
    cout << "char vec: " << count(cvec, csought) << endl;
    cout << "string vec: " << count(svec, ssought) << endl;
    return 0;
}
