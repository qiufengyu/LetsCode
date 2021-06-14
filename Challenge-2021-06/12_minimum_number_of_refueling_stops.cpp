#include "../header.h"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      priority_queue<int> pq;
      int res = 0, prev = 0;
      for (auto station: stations) {
        int location = station[0], capacity = station[1];
        startFuel -= (location - prev);
        while (startFuel < 0 && !pq.empty()) {
          startFuel += pq.top();
          pq.pop();
          res++;
        }
        if (startFuel < 0) {
          return -1;
        }
        pq.push(capacity);
        prev = location;
      }
      startFuel -= (target - prev);
      while (startFuel < 0 && !pq.empty()) {
        startFuel += pq.top();
        pq.pop();
        res++;
      }
      if (startFuel < 0) {
        return -1;
      }
      return res;
    }
};