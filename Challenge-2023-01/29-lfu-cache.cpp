#include "../header.h"

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> kv;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;
public:
    LFUCache(int capacity): capacity{capacity}, minFreq{0} {
        
    }
    
    int get(int key) {
        if (kv.find(key) != kv.end()) {
            update(key);
            return kv[key].first;
        }
        return -1;        
    }
    
    void put(int key, int value) {
        if (capacity > 0) {
            if (kv.find(key) != kv.end()) {
                kv[key].first = value;
                update(key);
                return;
            }
            // new key, should delete the least frequent one
            if (kv.size() == capacity) {
                int delKey = freqList[minFreq].front();
                kv.erase(delKey);
                pos.erase(delKey);
                freqList[minFreq].pop_front();
            }
            kv[key] = {value, 1};
            freqList[1].push_back(key);
            pos[key] = --freqList[1].end();
            minFreq = 1;
        }        
    }

    void update(int key) {
        freqList[kv[key].second].erase(pos[key]);
        kv[key].second++;
        freqList[kv[key].second].push_back(key);
        pos[key] = --freqList[kv[key].second].end();
        if (freqList[minFreq].empty()) {
            minFreq++;
        }
    }
};