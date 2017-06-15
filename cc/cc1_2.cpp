//write code to reverse a C-style string.
#include <iostream>
#include <cstring>  //strlen
//#include <string>
using namespace std;

// swap two chars
void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

// format param can be char* because we know where to end from '\0'
void reverse_cstr1(char *s)
{
    int len = strlen(s);
    int half_len = len / 2;
    for(int i = 0; i < half_len; ++i)
    {
        // NOTE last valid char is s[len-1]
        swap(s[i], s[len - 1 - i]);
    }
}

void reverse_cstr2(char *s)
{
    char *left = s;
    char *right = s + strlen(s) - 1;
    while(left < right)
    {
        swap(*left++, *right--);
    }
}

int main()
{
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    cout << "Before reverse1, str = " << s1 << endl;
    reverse_cstr1(s1);
    cout << "After reverse1, str = " << s1 << endl;
    reverse_cstr2(s1);
    cout << "After reverse2, str = " << s1 << endl;
}
