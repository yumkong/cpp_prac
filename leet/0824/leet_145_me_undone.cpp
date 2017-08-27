// implement a data structure for Least Recently Used (LRU) cache. 
// should support get(key), put(key, value) 
// follow up: can you do it with O(1) time complexity => hash table
#include <queue> // priority_queue
#include <map>
#include <iostream>
#include <utility>
using namespace std;

struct Comp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    { return p1.second > p2.second; }   // top is the least occur cnt
};

class LRUCache {
private:
    int cnt;
    int cap;
    // NOTE add vector<pair<int, int>> as the 2nd argu is necessary
    priority_queue<pair<int, int>, vector<pair<int,int> >, Comp> pq; // <key, last occur cnt>
    map<int, int> mp; // <key, val>
public:
    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
    }
    // value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
        if(mp.count(key) > 0) 
        {
            return mp[key];
            ++cnt;
            auto tmp = pq.top();
            mp.erase(tmp.first);
            pq.pop(); pq.push({key, cnt});
        }
        else return -1;
    }
    // Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
    void put(int key, int value) {
        ++cnt;
        if(mp.size() < cap)
        {
            pq.push({key, cnt});
            mp[key] = value;
        }
        else // already reach capacity
        {
            // if the key already exist
            if(mp.count(key) > 0)
            {
                mp[key] = value;
                pq.pop(); pq.push({key, cnt});
            }
            else
            {
                auto tmp = pq.top(); pq.pop();
                mp.erase(tmp.first); // erase the key's term
                pq.push({key, cnt});
                mp[key] =  value;
            }
        }
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
