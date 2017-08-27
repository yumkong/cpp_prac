// implement a data structure for Least Recently Used (LRU) cache. 
// should support get(key), put(key, value) 
// follow up: can you do it with O(1) time complexity => hash table
#include <list> // priority_queue
#include <unordered_map>
#include <iostream>
#include <utility>
#include <iterator>
using namespace std;

class LRUCache {
private:
    int cap;
    // NOTE add vector<pair<int, int>> as the 2nd argu is necessary
    unordered_map<int, list<pair<int, int> >::iterator> mp; // <key, last occur cnt>
    list<pair<int, int> > lst; // <key, val>
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    // value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
        auto found_it = mp.find(key);
        if(found_it == mp.end()) return -1; // not found
        //move the node corresponding to key to front 
        lst.splice(lst.begin(), lst, found_it->second);
        return found_it->second->second;
    }
    // Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
    void put(int key, int value) {
        auto found_it = mp.find(key);
        if(found_it != mp.end())
        {
            lst.splice(lst.begin(), lst, found_it->second);
            found_it->second->second = value;
            return;
        }
        if(mp.size() == cap) // already reach capacity
        {
            int key_to_del = lst.back().first;
            lst.pop_back();
            mp.erase(key_to_del);
        }
        //Inserts a new element at the beginning of the list, right before its current first element
        lst.emplace_front(key, value);
        mp[key] =  lst.begin();
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);                    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);                    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}
