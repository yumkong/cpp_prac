#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	map<int, int> mp;
	
	vector<int> vi;
	vector<vector<int> > vvi(3,vi);
	cout << "vector len = " << vvi.size() << endl;
	
	mp[0] = 1;
	mp[6] = 33;
	vvi[0].push_back(12);
	int numRows = 2;
	vector<char> vc; //empty vector of char
    vector< vector <char> > vvc(numRows, vc);
	vvc[0].push_back('a');
	cout << vvc[0][0] << endl;
	(vvi[mp[0]]).push_back(666);
	cout << vvi[0][0] << vvi[mp[0]][0] << endl;
	cout << mp[4] << mp[mp[0]] << endl;
    int bignum = 1e9;
	cout << bignum << endl;
    return 0;
}