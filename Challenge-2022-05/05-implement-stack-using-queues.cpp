#include "../header.h"

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();        
    }
};
