#include "../header.h"

class MyHashMap {
    vector<vector<int>> _m;
public:
    MyHashMap(): _m {1001, vector<int>(1001, -1)} {

    }
    
    void put(int key, int value) {
        _m[key/1000][key % 1001] = value;
    }
    
    int get(int key) {
        return _m[key/1000][key % 1001];
    }
    
    void remove(int key) {
        _m[key / 1000][key % 1001] = -1;
    }
};