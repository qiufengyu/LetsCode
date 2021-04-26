#include "../header.h"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int sumBricks = 0;
        for (int i = 1; i < heights.size(); i++) {
          if (heights[i-1] < heights[i]) {
            int tempCost = heights[i] - heights[i-1];
            minHeap.push(tempCost);
            if (minHeap.size() > ladders) {
              sumBricks += minHeap.top();
              minHeap.pop();
            }
            if (sumBricks > bricks) {
              return i - 1;
            } 
          }
        }
        return heights.size() - 1;
    }
};