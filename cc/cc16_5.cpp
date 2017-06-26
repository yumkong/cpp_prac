// find whether your machine is big endian or little endian
#include <iostream>
using namespace std;

#define BIG_END 0
#define LITTLE_END 1

int testByteOrder()
{ 
    // short contains only two bytes
    // big endian 0 1, little endian 1 0
    short int word = 0x0001;
    char *byte = (char *)&word;
    return (byte[0]? LITTLE_END: BIG_END);
}

int main()
{
    string arr[] = {"big endian", "little endian"};
    // 0 - big, 1 - little
    int index = testByteOrder();
    cout << "This machine is " << arr[index] << endl;
    return 0;
}
