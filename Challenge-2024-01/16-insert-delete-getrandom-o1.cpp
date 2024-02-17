#include "../header.h"

class RandomizedSet {
    unordered_map<int, int> m;
    int size;
    vector<int> v;
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
            size++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.count(val)) {
            int idx = m[val];
            size--;
            v[idx] = v[size];
            m[v[size]] = idx;
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */