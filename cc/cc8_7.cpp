#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef set<vector<int> > sv;
typedef vector<int> vi;

class Coin
{
private:
    int quarters; // 25
    int dimes;  // 10
    int nickels; // 5
    int pennies; // 1
public:
    // represent n cents with 4 types of coins
    Coin(int i, int j, int k, int m): quarters(i), dimes(j), nickels(k), pennies(m) { }
    sv representCent(int, vi);
    ~Coin() {}
};

sv Coin::representCent(int n, vi coin_num)
{
    // num of [25 10 5 1] respectively
    sv tmpMoneySet, tmp1, tmp2, tmp3, tmp4;
    int curSum = coin_num[0] * quarters + coin_num[1] * dimes + coin_num[2] * nickels + coin_num[3] * pennies;
    //cout << curSum << endl;
    if(curSum == n)
    {
        tmpMoneySet.insert(coin_num);
        //return tmpMoneySet;
    }
    else if(curSum > n)
    {
        //return tmpMoneySet;
    }
    else
    {
        vi cn1 = coin_num;
        ++cn1[0];
        tmp1 = representCent(n, cn1);
        vi cn2 = coin_num;
        ++cn2[1];
        tmp2 = representCent(n, cn2);
        vi cn3 = coin_num;
        ++cn3[2];
        tmp3 = representCent(n, cn3);
        vi cn4 = coin_num;
        ++cn4[3];
        tmp4 = representCent(n, cn4);
        // concatenate setsi
        tmpMoneySet.insert(tmp1.begin(), tmp1.end());
        tmpMoneySet.insert(tmp2.begin(), tmp2.end());
        tmpMoneySet.insert(tmp3.begin(), tmp3.end());
        tmpMoneySet.insert(tmp4.begin(), tmp4.end());
    }
    return tmpMoneySet;
}

int main()
{
    Coin* pc = new Coin(25, 10, 5, 1);
    sv goodMoneySet;
    vi moneyComb(4, 0);
    int total = 30;
    goodMoneySet = pc->representCent(total, moneyComb);
    typename sv::size_type setnum = goodMoneySet.size(); 
    cout << setnum <<  " combinations can sum to " << total << " cents:" << endl;
    for(sv::iterator iter = goodMoneySet.begin(); iter != goodMoneySet.end(); ++iter)
    {
        vi tm = *iter;
        cout << "Quarter: " << tm[0] << ", Dime: " << tm[1] << ", nickel: " << tm[2] << ", penny: " << tm[3] << endl;
    }
    return 0;
}
