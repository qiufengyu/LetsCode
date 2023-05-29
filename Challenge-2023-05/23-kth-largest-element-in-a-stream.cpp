#include "../header.h"

class KthLargest {
    priority_queue<int,vector<int>, greater<int>> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums): pq{nums.begin(), nums.end()}, kth {k} {
        while (pq.size() > kth) {
            pq.pop();
        }
    }
    
    // the problem ensures that #elements >= k
    int add(int val) {
        pq.push(val);
        if (pq.size() > kth) {
            pq.pop();
        }
        return pq.top();        
    }
};