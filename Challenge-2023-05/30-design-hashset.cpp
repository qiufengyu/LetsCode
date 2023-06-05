#include "../header.h"

int const SZ = 1000001 / 32 + 1;

class MyHashSet {
    int arr[SZ];
public:
    MyHashSet() {
        memset(arr, 0, sizeof(arr));
    }
    
    void add(int key) {
        int idx = key / 32;
        int offset = key % 32;
        arr[idx] |= (1 << offset);
    }
    
    void remove(int key) {
        int idx = key / 32;
        int offset = key % 32;
        arr[idx] &= (~(1 << offset));
    }
    
    bool contains(int key) {
        int idx = key / 32;
        int offset = key % 32;
        return (arr[idx] & (1 << offset)) != 0;
    }
};