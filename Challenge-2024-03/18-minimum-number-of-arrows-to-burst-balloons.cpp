#include "../header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int res = 1;
        int maxEnd = points[0][1];
        for (int i = 1; i < n; i++) {
            if (maxEnd < points[i][0]) {
                res++;
                maxEnd = points[i][1];
            }
            maxEnd = min(maxEnd, points[i][1]);
        }
        return res;
    }
};