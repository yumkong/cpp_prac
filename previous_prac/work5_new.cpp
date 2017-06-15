#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const int WARRIOR_TOTAL_NUM = 5;
const string warriorName[WARRIOR_TOTAL_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};

class Warrior
{
	int id;
	int life_value;
	int attack_power;
	string warrior_name;
public:
    //construtor
    Warrior(int _id, int _lv, int _ap, string _str):id(_id),life_value(_lv),attack_power(_ap),warrior_name(_str) {}
};

class Headquater
{
	int life_len; // sheng ming yuan
	int cur_warrior_idx;
	//int warrior_num;
	string hq_name; //headquater name
	vector<Warrior> warriorVec;
	// num of each warrior kind: "dragon", "ninja", "iceman", "lion", "wolf"
	vector<int> warriorNum; 
	vector<int> warriorOrder;
	vector<int> warriorInitLife;
public:
    Headquater(const string &hq_nm, const vector<int> &w_oder):
	    life_len(0), cur_warrior_idx(0), hq_name(hq_nm), warriorNum(WARRIOR_TOTAL_NUM, 0), 
		warriorInitLife(WARRIOR_TOTAL_NUM, 0), warriorOrder(w_oder) {}
	void set_lifelen(int llen)
	{
		life_len = llen;
	}
	void set_warriorInitlife(vector<int> &ilife)
	{
		warriorInitLife = ilife;
	}
	void reset()
	{
		warriorVec.clear();
		//set all warrior num to 0
		fill(warriorNum.begin(), warriorNum.end(), 0);
		cur_warrior_idx = 0;
	}
    // xxxxx
	int get_next_warrior_index()
	{
		int idx = 0, i = 0;
		for(i = 0; i < WARRIOR_TOTAL_NUM; ++i)
		{
			idx = (cur_warrior_idx + i) % WARRIOR_TOTAL_NUM;
			if(life_len >= warriorInitLife[warriorOrder[idx]])
				break;
		}
		// curr_idx+1 and return curr_idx
		if (i < WARRIOR_TOTAL_NUM)
		{
			cur_warrior_idx = (idx + 1) % WARRIOR_TOTAL_NUM;
			return warriorOrder[idx];
		}
		else
		{
			return -1;
		}
	}
	// xxxxx
	int add_warrior(int cnt)
	{
		int wIdx = get_next_warrior_index();
		if(wIdx >= 0)
		{
			++warriorNum[wIdx];
			life_len -= warriorInitLife[wIdx];
			// index, life_value, attack_power, name
			warriorVec.push_back(Warrior(cnt+1, warriorInitLife[wIdx], warriorInitLife[wIdx], warriorName[wIdx]));
			cout << hq_name << " " << warriorName[wIdx] << " ";
			cout << cnt+1 << " born with strength ";
			cout << warriorInitLife[wIdx] << ",";
			cout << warriorNum[wIdx] << " " << warriorName[wIdx];
			cout << " in " << hq_name << " headquarter" << endl;
		}
		else
		{
			cout << hq_name << " headquarter stops making warriors" << endl;
			return -1;
		}
	}
};

int main()
{
	int redArr[WARRIOR_TOTAL_NUM] = {2, 3, 4, 1, 0};
	const vector<int> redOrder(redArr, redArr+WARRIOR_TOTAL_NUM);
	int blueArr[WARRIOR_TOTAL_NUM] = {3, 0, 1, 2, 4};
	const vector<int> blueOrder(blueArr, blueArr+WARRIOR_TOTAL_NUM);
	// create red and blue headQuater
	Headquater redHQ("red", redOrder);
	Headquater blueHQ("blue", blueOrder);
	 
	int caseNum, lifeVal, l1, l2, l3, l4, l5;
	
	// how cases need to be tested?
	cin >> caseNum;
	for(int i = 0; i < caseNum; i++)
	{
		// reset headquaters
		redHQ.reset();
		blueHQ.reset();
		// life span of each headquater
		cin >> lifeVal;
		redHQ.set_lifelen(lifeVal);
		blueHQ.set_lifelen(lifeVal);
		cin >> l1 >> l2 >> l3 >> l4 >> l5;
		// print out a new case
		cout << "Case:" << i+1 << endl;
		vector<int> initLife;
		initLife.push_back(l1);
		initLife.push_back(l2);
		initLife.push_back(l3);
		initLife.push_back(l4);
		initLife.push_back(l5);
		redHQ.set_warriorInitlife(initLife);
		blueHQ.set_warriorInitlife(initLife);
		// initialize these flags each time
		int state_red = 1, state_blue = 1;
	    int cnt = 0;
		while(state_red > 0 || state_blue > 0)
		{
			if(state_red > 0)
			{
				cout << setfill('0') << setw(3) << cnt << " ";
				state_red = redHQ.add_warrior(cnt);
			}
			if(state_blue > 0)
			{
				cout << setfill('0') << setw(3) << cnt << " ";
				state_blue = blueHQ.add_warrior(cnt);
			}
			++cnt;
		}
	}
}