#include "../header.h"

class MyCircularQueue {
    vector<int> _v;
    int head, tail, size, length;
public:
    MyCircularQueue(int k): _v(k), size(k) {
        head = 0;
        tail = -1;
        length = 0;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {            
            ++tail;
            tail %= size;
            _v[tail] = value;
            ++length;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ++head;
        head %= size;
        --length;
        return true;
    }
    
    int Front() {
        if (!isEmpty()) {
            return _v[head];
        }
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) {
            return _v[tail];
        }
        return -1;
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == size;
    }
};