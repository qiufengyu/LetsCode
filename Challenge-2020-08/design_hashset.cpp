#include "../header.h"

class MyHashSet {
    vector<bool> mem_;
public:
    /** Initialize your data structure here. */
    MyHashSet(): mem_(vector<bool>(1000001, 0)) {
    
    }
    
    void add(int key) {
        mem_[key] = true;
    }
    
    void remove(int key) {
        mem_[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return mem_[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */