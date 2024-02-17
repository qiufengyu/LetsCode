#include "../header.h"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), h = heights[0];
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0, res = 0;
        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            // use ladder or bricks
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    int tp = pq.top();
                    if (tp > bricks) {
                        return i-1;
                    } else {
                        bricks -= tp;
                    }
                    pq.pop();
                }
            }
            res = i;
        }
        return res;
    }
};