#include <iostream>
#include <vector>
//#include <algorithm>
//#include <functional>
#include <numeric>
using namespace std;

int SumSquares(int total, int value)
{
	return total + value * value;
}

template <class T>
void PrintInterval(T first, T last)
{
	for(; first != last; ++first)
		cout << *first << " ";
	cout << endl;
}

template <class T>
class SumPowers
{
private:
    int power;
public:
    SumPowers(int p):power(p) {}
	const T operator()(const T& total, const T& value)
	{
		T v = value;
		for(int i = 0; i < power - 1; ++i)
			v = v * value;
		return total + v;
	}
};

int main()
{
	const int SIZE = 10;
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v(a1, a1 + SIZE);
	cout << "1)";
	PrintInterval(v.begin(), v.end());
	int result = accumulate(v.begin(), v.end(), 0, SumSquares);
	cout << "2)";
	cout << "SquareSum = " << result << endl;
    // how to use the functional class
	int result2 = accumulate(v.begin(), v.end(), 0, SumPowers<int>(2));
	cout << "3)";
	cout << "SquareSum2 = " << result2 << endl;
	
	int result3 = accumulate(v.begin(), v.end(), 0, SumPowers<int>(3));
	cout << "4)";
	cout << "CubicSum = " << result3 << endl;
	
}