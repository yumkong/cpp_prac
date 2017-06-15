#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Warrior
{
public:
    //int lifeval;
    string name;
    int bornNum;
public:
    //Warrior(string _name, int b):name(_name), bornNum(b){}
    void setVal(string _name, int b)
    {
	name = _name;
        bornNum = b;
    }
    void Born()
    {
	bornNum++;
    }
};

class Headquater
{
public:
    int lifelen;
    int wOrder[5];
    int wLifeval[5];
    int wNum[5];
    int currW;
    string name;
public:
    //Headquater(int _len,int a[5], int aa[5], int aaa[5], int curr, string _name):lifelen(_len),wOrder(a),wLifeval(aa),wNum(aaa),currW(curr),name(_name){}
    void setVal(int _len,int *wo, int *wl, int *wn, int curr, string _name)
    {
	lifelen = _len;
	for(int i = 0; i < 5; i++)
	{
            wOrder[i] = wo[i];
	    wLifeval[i] = wl[i];
	    wNum[i] = wn[i];
	}
	currW = curr;
	name = _name;
    }
    int WarriorGen()
    {
	int returnval = -1;
	for(int i = 0; i < 5; i++)
	{
	    if(lifelen >= wLifeval[wOrder[currW]])
	    {
		lifelen -= wLifeval[wOrder[currW]];
		returnval = wOrder[currW];
 		wNum[wOrder[currW]]++;
		currW = (currW + 1)%5;
		//wNum[wOrder[currW]]++;
		
		return returnval;
	    }
	    else
	    {
		currW = (currW + 1)%5;
	    }
	}
	return returnval;
    }
};



int main()
{
    int casenum, lifeval;
    int l1,l2,l3,l4,l5;
    Warrior warr[5];
    Headquater head[2];
    warr[0].setVal("dragon",0);
    warr[1].setVal("ninja",0);
    warr[2].setVal("iceman",0);
    warr[3].setVal("lion",0);
    warr[4].setVal("wolf",0);
    int h0order[5] = {2,3,4,1,0};
    int h1order[5] = {3,0,1,2,4};
    int initnum[5] = {0,0,0,0,0};
    cin >> casenum;
    for(int i = 0; i < casenum; i++)
    {
	int state1 = 0, state2 = 0;
	int cnt = 0;
        int tmp;
	cin >> lifeval;
	cin >> l1 >> l2 >> l3 >> l4 >> l5;
        int lifelength[5] = {l1,l2,l3,l4,l5};
	head[0].setVal(lifeval,h0order, lifelength, initnum, 0, "red");
	head[1].setVal(lifeval,h1order, lifelength, initnum, 0, "blue");
	while(state1 == 0 || state2 == 0)
	{
	    if(state1 == 0)
	    {
	        tmp = head[0].WarriorGen();
			cout << setfill('0') << setw(3) << cnt << " ";
	        if(tmp >= 0)
			{
				warr[tmp].Born();
				//cout << setfill('0') << setw(3) << cnt << " ";
						cout << head[0].name << " " << warr[tmp].name << " ";
				cout << cnt+1 << " born with strength ";
				cout << head[0].wLifeval[tmp] << ",";
				cout << head[0].wNum[tmp] << " " << warr[tmp].name;
				cout << " in red headquarter" << endl;
			}
			else
			{
				cout << "red headquarter stops making warriors" << endl;
				state1 = 1;
			}
	    }
	    if(state2 == 0)
            {
                tmp = head[1].WarriorGen();
                cout << setfill('0') << setw(3) << cnt << " ";
                if(tmp >= 0)
                {
                    warr[tmp].Born();
                    //cout << setfill('0') << setw(3) << cnt << " ";
                    cout << head[1].name << " " << warr[tmp].name << " ";
                    cout << cnt+1 << " born with strength ";
                    cout << head[1].wLifeval[tmp] << ",";
                    cout << head[1].wNum[tmp] << " " << warr[tmp].name;
                    cout << " in blue headquarter" << endl;
                }
                else
                {
                    cout << "blue headquarter stops making warriors" << endl;
		    state2 = 1;
                }
            }
	    cnt++;
	}
    } 

}
