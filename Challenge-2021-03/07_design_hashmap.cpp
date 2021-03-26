#include "../header.h"

class MyHashMap {
    vector<vector<int>> data;
public:
    /** Initialize your data structure here. */
    MyHashMap(): data(1001, vector<int>(1001, -1)) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int a = key / 1000;
        int b = key % 1001;
        data[a][b] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int a = key / 1000;
        int b = key % 1001;
        return data[a][b];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int a = key / 1000;
        int b = key % 1001;
        data[a][b] = -1;
    }
};