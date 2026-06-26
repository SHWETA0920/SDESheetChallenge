#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos; 
   
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyVal[key].second;
        freqList[freq].erase(pos[key]);
        if(freqList[freq].empty()) {
            freqList.erase(freq);
            if(minFreq == freq) minFreq++;
        }

        freq++;
        keyValFreq[key].second = freq;
        freqList[freq].push_front(key);
        pos[key] = freqList[freq].begin();
    }

    int get(int key) {
        if(keyValFreq.find(key) == keyValFreq.end()) return -1;

        updateFreq(key);
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if(cap == 0) return;

        if(keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if(keyValFreq.size() == cap) {
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if(freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyValFreq.erase(keyToRemove);
            pos.erase(keyToRemove);
        }

        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};
