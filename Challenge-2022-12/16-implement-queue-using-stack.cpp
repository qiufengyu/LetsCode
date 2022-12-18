#include "../header.h"

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int r = peek();
        s2.pop();
        return r;        
    }
    
    int peek() {
        if (!empty()) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }
        return -1;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();        
    }
};