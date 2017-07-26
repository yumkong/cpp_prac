//(1) check an array(e.g. {1,2,3,4}) can be used to assign or construct a vector
// => only in c++11 (-std=c++11)
//(2) INT_MAX, INT_MIN
// => include header file (climits)
// (3) {a,b} can be used to initialize a pair!!! == make_pair(a,b)
// => only in c++11 (-std=c++11)
#include <vector>
#include <iostream>
#include <utility> // pair
#include <climits> // INT_MAX == ~(1<<31), INT_MIN = (1<<31)
using namespace std;

int main()
{
    /*(1)
    vector<int> a = {1,2,3,4,5};
    vector<int> b({5,6,7,8,9,0,36});
    for(int i = 0; i < a.size(); ++i) cout << a[i] << " " ;
    cout << endl;
    for(int i = 0; i < b.size(); ++i) cout << b[i] << " " ;
    cout << endl;*/
    /*(2)
    cout << ~(1<<31) << endl;
    cout << INT_MAX << endl;
    cout << (1 << 31) << endl;
    cout << INT_MIN << endl;*/
    // (3)
    vector<pair<int, int> > vp;
    vp.push_back(make_pair(1,2));
    vp.push_back({5,6});
    for(int i = 0; i < vp.size();++i)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }
    return 0;
}
