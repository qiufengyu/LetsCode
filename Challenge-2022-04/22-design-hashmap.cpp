#include "../header.h"

class MyHashMap {
    vector<vector<int>> m;
public:
    MyHashMap(): m(1001, vector<int>(1001, -1)) {
        
    }
    
    void put(int key, int value) {
        m[key / 1000][key % 1001] = value;
    }
    
    int get(int key) {
        return m[key/1000][key%1001];
    }
    
    void remove(int key) {
        m[key / 1000][key % 1001] = -1;
    }
};