//design a data structure that supports insert, remove and getRandom in average O(1) time
// 0810 accepted !!!
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime> // time
#include <vector>
#include <map>
using namespace std;
// RAND returns a pseudo-random int in the range [0, INT_MAX]

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        // initialize random seed
        srand(time(NULL));
    }
    
    //Inserts a value to the collection. Returns true if the collection did not already contain the specified element
    bool insert(int val) {
        arr.push_back(val);
        dict[val].push_back(arr.size() - 1); // add its index in dic[val]
      //  cout << "create: dict[" << val << "] = " << arr.size() - 1 << endl;
        return dict[val].size() == 1;
    }

    // Removes a value from the collection. Returns true if the collection contained the specified element
    bool remove(int val) {
        if(dict.count(val) == 0) return false;
        int idx = dict[val].back(); 
    //    cout << "pop: dict[" << val << "] = " << idx << endl;
//        if(dict.count(10) > 0) {auto tm = dict[10]; cout << "dict[10] idx = "; for(auto &i: tm) cout << i << " "; cout << endl; }
  //      if(dict.count(20) > 0) {auto tm = dict[20]; cout << "dict[20] idx = "; for(auto &i: tm) cout << i << " "; cout << endl; }
    //    if(dict.count(30) > 0) {auto tm = dict[30]; cout << "dict[30] idx = "; for(auto &i: tm) cout << i << " "; cout << endl; }
        // swap arr[idx] and arr[arr.size()-1] if idx != arr.size()-1
        // modify the dict accordingly
        if(arr.size() - 1 != idx)
        {
            int tmp = arr.back();
            arr[idx] = tmp;
            // update the new index
            dict[tmp].pop_back(); // remove the index of "size()-1"
            // 0810: assert according to order
            if(dict[tmp].size() == 0 || dict[tmp].back() < idx) dict[tmp].push_back(idx);
            else
            {
                vector<int>::iterator it = dict[tmp].begin();
                while(it != dict[tmp].end())
                {
                    if(idx < *it) {dict[tmp].insert(it, idx); break;}
                    ++it;
                }
            }
        }
        dict[val].pop_back(); // last index of val
        if(dict[val].size() == 0) 
        {
            dict.erase(val);
        //    cout << "Erasing the dict of val = " << val << endl;
        }
        // safely remove last elem from vector arr since it has been copied to idx position
        arr.pop_back();
        return true;
    }

    // Get a random element from the collection
    int getRandom() {
        //cout << "arr size = " << arr.size() << endl;
        return arr[rand() % arr.size()];
    }
private:
    //map<int, vector<int> > dict;
    map<int, vector<int> > dict;
    vector<int> arr;
};


int main()
{
    //["ins","ins","ins","ins","ins","ins","rem","rem","rem","rem","getR","getR","getR","getR","getR","getR","getR","getR","getR","getR"]
    //[[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]
    RandomizedCollection obj; // = new RandomizedCollection();
    obj.insert(10);
    obj.insert(10);
    obj.insert(20);
    obj.insert(20);
    obj.insert(30);
    obj.insert(30);
    obj.remove(10); obj.remove(10); obj.remove(30); obj.remove(30);
    cout << "random1 = " << obj.getRandom() << endl;
    cout << "random2 = " << obj.getRandom() << endl;
    cout << "random3 = " << obj.getRandom() << endl;
    cout << "random4 = " << obj.getRandom() << endl;
    cout << "random5 = " << obj.getRandom() << endl;
    cout << "random6 = " << obj.getRandom() << endl;
    cout << "random7 = " << obj.getRandom() << endl;
    cout << "random8 = " << obj.getRandom() << endl;
    cout << "random9 = " << obj.getRandom() << endl;
    cout << "random10 = " << obj.getRandom() << endl;
    return 0;
}
