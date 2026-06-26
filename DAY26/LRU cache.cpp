#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    list<int> dl;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;

public:
    LRUCache(int capacity)
    {
        n = capacity;
    }

    void recent(int key) {
        dl.erase(mp[key].first);
        dl.push_front(key);
        mp[key].first = dl.begin();
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end()) {
            recent(key);
            return mp[key].second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            mp[key].second = value;
            recent(key);
        }
        else {
            if(dl.size() == n) {
                int k1 = dl.back();
                dl.pop_back();
                mp.erase(k1);
            }

            dl.push_front(key);
            mp[key] = {dl.begin(), value};
        }
    }
};
