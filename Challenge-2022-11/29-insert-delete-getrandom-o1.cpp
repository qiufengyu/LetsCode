#include "../header.h"

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
    int size;
public:
    RandomizedSet(): size {0} {
        
    }
    
    bool insert(int val) {
        if (m.count(val) == 0) {
            if (v.size() > size) {
                v[size] = val;                
            } else {
                v.push_back(val);
            }            
            m[val] = size;
            ++size;
            return true;
        }
        return false;        
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) {
            return false;
        }
        int idx = m[val];
        --size;
        int lastElement = v[size];
        m[lastElement] = idx;
        v[idx] = lastElement;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % size];
    }
};