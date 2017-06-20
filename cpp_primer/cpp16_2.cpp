// accept an ostream reference and a val, write val to stream
#include <iostream> // cout
#include <string>
#include <fstream>  // file stream
#include <sstream> // stringstream
using namespace std;

template <typename T1, typename T2>
T1& print(T1& s, T2 val)
{
    s << val;
    return s;
}

int main()
{
    int ival = -3;
    double dval = 0.66;
    float fval = -12.6;
    string sval = "this a test";

    // write out to cout
    print(cout, ival) << endl;
    print(cout, dval) << endl;
    print(cout, fval) << endl;
    print(cout, sval) << endl;
  
    // write out to file 
    ofstream fout("cpp16_2.txt");
    print(fout, ival) << endl;
    print(fout, dval) << endl;
    print(fout, fval) << endl;
    print(fout, sval) << endl;
    fout.close(); // remember to close file stream after using it

    // write out to stringstream
    string deststr;
    ostringstream sout(deststr);
    print(sout, ival) << endl;
    print(sout, dval) << endl;
    print(sout, fval) << endl;
    print(sout, sval) << endl;
    // for verification: output stringstream's string with cout
    cout << sout.str() << endl;

    return 0;
}
