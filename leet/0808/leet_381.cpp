//design a data structure that supports insert, remove and getRandom in average O(1) time
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
        return dict[val].size() == 1;
    }
    
    // Removes a value from the collection. Returns true if the collection contained the specified element
    bool remove(int val) {
        if(dict[val].size() == 0) return false;
        int idx = dict[val].back(); dict[val].pop_back(); // last index of val
        // swap arr[idx] and arr[arr.size()-1] if idx != arr.size()-1
        // modify the dict accordingly
        if(arr.size() - 1 != idx)
        {
            int tmp = arr.back();
            arr[idx] = tmp;
            // update the new index
            dict[tmp].pop_back(); // remove the index of "size()-1"
            dict[tmp].push_back(idx);
        }
        // safely remove last elem from vector arr since it has been copied to idx position
        arr.pop_back();
        return true;
    }
    
    // Get a random element from the collection
    int getRandom() {
        return arr[rand() % arr.size()];
    }
private:
    map<int, vector<int> > dict;
    vector<int> arr;
};


int main()
{
    //Your RandomizedCollection object will be instantiated and called as such:
    RandomizedCollection obj; // = new RandomizedCollection();
    cout << obj.insert(1) << endl;
    cout << obj.insert(2) << endl;
    cout << obj.insert(3) << endl;
    cout << obj.insert(4) << endl;
    cout << obj.insert(5) << endl;
    cout << obj.insert(6) << endl;
    cout << obj.remove(7) << endl;
    cout << "random val1 = " << obj.getRandom() << endl;
    cout << "random val2 = " << obj.getRandom() << endl;
    return 0;
}
