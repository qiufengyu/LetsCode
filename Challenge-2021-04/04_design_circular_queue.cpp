#include "../header.h"

class MyCircularQueue {
  vector<int> _m;
  int size;
public:
    MyCircularQueue(int k) {
      size = k;        
    }
    
    bool enQueue(int value) {
        if (_m.size() == size) {
          return false;
        }
        _m.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (_m.empty()) {
          return false;
        }
        _m.erase(_m.begin());
        return true;
    }
    
    int Front() {
        if (_m.empty()) {
          return -1;
        }
        return *_m.begin();
    }
    
    int Rear() {
        if (_m.empty()) {
          return -1;
        }
        return *(_m.end()-1);
    }
    
    bool isEmpty() {
        return _m.empty();
    }
    
    bool isFull() {
        return _m.size() == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */