#include "header.h"

class RandomizedSet {
private:
    map<int, int> m;
    vector<int> v;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet(): size {0} {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        } else {
            m[val] = size;
            v.push_back(val);
            size++;
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        } else {
            int index = m[val];
            m.erase(val);
            int last = v[size - 1];
            v[index] = last;
            m[last] = index;
            v.pop_back();
            size--;
        }
        return true;
    }
    
    /** Get a random element from the set. */
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

int main() {
    RandomizedSet randomSet;
    cout << randomSet.insert(0) << endl;
    cout << randomSet.insert(1) << endl;
    cout << randomSet.remove(0) << endl;
    cout << randomSet.insert(2) << endl;
    cout << randomSet.remove(1) << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;

    return 0;
}