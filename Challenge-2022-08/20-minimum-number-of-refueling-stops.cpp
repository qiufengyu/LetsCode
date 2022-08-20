#include "../header.h"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int res = 0, prev = 0;
        for (auto const station: stations) {
            int p = station[0], f = station[1];
            startFuel -= (p - prev);
            while (startFuel < 0 && !pq.empty()) {
                startFuel += pq.top();
                res++;
                pq.pop();
            }
            if (startFuel < 0) {
                return -1;
            }
            pq.push(f);
            prev = p;
        }
        startFuel -= (target - prev);
        while (startFuel < 0 && !pq.empty()) {
            startFuel += pq.top();
            res++;
            pq.pop();
        }
        if (startFuel < 0) {
            return -1;
        }
        return res;
    }
};