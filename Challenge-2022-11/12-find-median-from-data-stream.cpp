#include "../header.h"

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();
        // pq1 always hold more elements
        if (pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if (pq1.size() == pq2.size()) {
            return (pq1.top() + pq2.top()) / 2.0;
        }
        return pq1.top();        
    }
};