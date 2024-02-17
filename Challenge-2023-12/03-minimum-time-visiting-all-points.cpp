#include "../header.h"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            auto p1 = points[i], p2 = points[i+1];
            int dx = abs(p1[0] - p2[0]), dy = abs(p1[1] - p2[1]);
            int md = min(dx, dy);
            int vh = max(dx, dy) - md;
            res += (md + vh);
        }
        return res;
    }
};