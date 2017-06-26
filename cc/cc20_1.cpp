// add two numbers, not use + or any arithmetic operators
#include <iostream>
using namespace std;

//method 1: recursion
int Add1(int a, int b)
{
    if(b == 0) return a;
    int sum = a ^ b; // bit by bit  addition, without carry
    int carry = (a & b) << 1; // remember carry(if two bits both 1, then get a carry in upper bit)
    return Add1(sum, carry);
}

//method2: change method1 to iteration
int Add2(int a, int b)
{
    while(b != 0)
    {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}

int main()
{
    int a = 70, b = -13432;
    cout << Add1(a, b) << endl;
    cout << Add2(a, b) << endl;
    return 0;
}
