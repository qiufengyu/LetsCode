#include "../header.h"

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();        
    }
    
    bool empty() {
        return q.empty();
    }
};
