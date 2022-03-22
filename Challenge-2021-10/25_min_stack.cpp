#include "../header.h"

class MinStack {
private:
    stack<int> s;
    stack<int> ms;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (!ms.empty()) {
            int t = ms.top();
            if (t > val) {
                ms.push(val);
            } else {
                ms.push(t);
            }
        } else {
            ms.push(val);
        }
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};


int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}