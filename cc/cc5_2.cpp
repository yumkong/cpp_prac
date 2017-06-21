// represent a decimal in binary
// if cannot represent accurately, print "ERROR"
#include <iostream>
#include <string>
#include <cstdlib> //atoi()=> char[] to int
using namespace std;
 
string print_binary(string val)
{
    // 2nd param: position of first character considered to be searched
    int pos = val.find('.', 0);
    // integer part
    // substr 2nd param: size_t len
    int intpart = atoi(val.substr(0, pos).c_str());
    //starting from pos('.') to the end, e.g.: .125
    double decpart = atof(val.substr(pos, val.length() - pos).c_str());
    string intstr = "", decstr = "";
    // deal with integer part
    while(intpart > 0)
    {
        // upper bit always put to the front
        if(intpart & 1)
        {
            intstr = "1" + intstr;
        }
        else
        {
            intstr = "0" + intstr;
        }
        intpart >>= 1;
    }
    // deal with decimal part
    while(decpart > 0)
    {
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1)
        {
            decstr += "1";
            decpart -= 1;
        }
        else
        {
            decstr += "0";
        }
    }
    return intstr + "." + decstr;
}

int main()
{
    string val = "6.25";
    cout << print_binary(val) << endl;
    return 0;
}
