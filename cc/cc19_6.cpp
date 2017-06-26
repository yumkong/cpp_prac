// num to string
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string numtostring(int num)
{
    string sb("");
    int a = 10, len = 1; // len - how many digits in this number
    while(pow(a, len) < num)
    {
        ++len;     
    }
    string wordArr1[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " };
    string wordArr11[] = {"", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string wordArr10[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string wordArr100[] = {"", "Hundred ", "Thousand "};
    int tmp;
    if(num == 0)
    {
        sb.append("Zero");
    }
    else
    {
        if(len > 3 && len % 2 == 0)
        {
            ++len;
        }
        do{
            // number greater than 999
            if(len > 3)
            {
                tmp = (num / pow(10, len - 2));
                // if tmp is 2 digit number and not a multiple of 10
                if(tmp / 10 == 1 && tmp % 10 != 0)
                {
                    sb.append(wordArr11[tmp % 10]);
                }
                else
                {
                    sb.append(wordArr10[tmp / 10]);
                    sb.append(wordArr1[tmp % 10]);
                }
                if(tmp > 0)
                {
                    sb.append(wordArr100[len / 2]);
                }
                num = num % (int)pow(10, len - 2);
                len = len - 2;
            }
            else // less than 1000
            {
                tmp = num / 100;
                if(tmp != 0)
                {
                    sb.append(wordArr1[tmp]);
                    sb.append(wordArr100[len / 2]);
                }
                tmp = num % 100;
                if(tmp / 10 == 1 && tmp % 10 != 0)
                {
                    sb.append(wordArr11[tmp % 10]);
                }
                else
                {
                    sb.append(wordArr10[tmp/ 10]);
                    sb.append(wordArr1[tmp % 10]);
                }
                len = 0;
            }
        }while(len > 0);
    }
    return sb;
}

int main()
{
    cout << "99999 = " << numtostring(99999) << endl;
    return 0;
}
