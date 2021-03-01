#include "../header.h"

class FreqStack {
    unordered_map<int, int> frequency;
    multimap<int, int, greater_equal<int>> m;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        m.insert({++frequency[x], x});
    }
    
    int pop() {
        int x = m.begin()->second;
        m.erase(m.begin());
        --frequency[x];
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
