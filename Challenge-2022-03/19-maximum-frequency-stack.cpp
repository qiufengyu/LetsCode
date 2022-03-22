#include "../header.h"

class FreqStack {
    unordered_map<int, int> freq;
    multimap<int, int, greater_equal<int>> m;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++freq[val];
        m.insert({freq[val], val});
    }
    
    int pop() {
        int res = m.begin()->second;
        m.erase(m.begin());
        --freq[res];
        return res;
    }
};