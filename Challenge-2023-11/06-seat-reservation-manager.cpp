﻿#include "../header.h"

class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int tp = pq.top();
        pq.pop();
        return tp;        
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};