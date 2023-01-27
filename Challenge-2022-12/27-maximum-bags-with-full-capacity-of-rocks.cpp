#include "../header.h"

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size(), res = 0;
        priority_queue<int, vector<int>, greater<int>> rest;
        for (int i = 0; i < n; ++i) {
            int r = capacity[i] - rocks[i];
            if (r > 0) {
                rest.push(r);
            } else {
                ++res;
            }
        }
        while (additionalRocks > 0 && !rest.empty()) {
            additionalRocks -= rest.top();
            rest.pop();
            res += (additionalRocks >= 0);
        }
        return res;
    }
};