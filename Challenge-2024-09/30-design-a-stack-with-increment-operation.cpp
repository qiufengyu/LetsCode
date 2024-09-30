#include "../header.h"

class CustomStack {
    vector<int> cs;
    int sz ;
public:
    CustomStack(int maxSize): sz{maxSize} {
        
    }
    
    void push(int x) {
        if (cs.size() < sz) {
            cs.push_back(x);
        }
    }
    
    int pop() {
        if (!cs.empty()) {
            int res = cs.back();
            cs.pop_back();
            return res;
        }
        return -1;        
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min((int)cs.size(), k); i++) {
            cs[i] += val;
        }
    }
};