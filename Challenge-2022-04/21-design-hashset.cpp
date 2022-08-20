#include "../header.h"

class MyHashSet {
    int m[31251];
public:
    MyHashSet() {
        memset(m, 0, sizeof(m));
    }
    
    int getIndex(int key) {
        return key / 32;
    }

    int getBit(int key) {
        return (1 << (key % 32));
    }
    
    void add(int key) {
        m[getIndex(key)] |= getBit(key);
        
    }
    
    void remove(int key) {
        m[getIndex(key)] &= (~getBit(key));
    }
    
    bool contains(int key) {
        return (m[getIndex(key)] & getBit(key)) != 0;
    }
};