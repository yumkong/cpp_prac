#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    string owner;
    double amount;
    static double interestRate;
public:
    Account(string own, double amnt)
    {
        owner = own;
        amount = amnt;
    }
    // compute balance
    void applyint()
    {
        amount += amount * interestRate;
    }
    //return current rate
    static double rate()
    {
        return interestRate;
    }
    //set a new interest rate
    static void rate(double newRate)
    {
        interestRate = newRate;
    }
    // deposit
    double deposit(double amnt)
    {
        amount += amnt;
        return amount;
    }
    // withdraw
    bool withdraw(double amnt)
    {
        if(amount < amnt) return false;
        else 
        {
            amount -= amnt;
            return true;
        }
    }
    //
    double getBalance()
    {
        return amount;
    }
};
//*** set the static member var outside the class definition 
double Account::interestRate = 2.5;

int main()
{
    Account myAcc("yumkong", 566.8);
    cout << "current rate is " << myAcc.rate() << endl;
    return 0;
}
