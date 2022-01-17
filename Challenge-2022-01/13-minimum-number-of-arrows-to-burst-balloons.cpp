#include "../header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> const& a, vector<int> const& b) -> bool {
            return a[1] < b[1];
        });
        int overlap = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            vector<int> p = points[i];
            if (p[0] <= end) {
                end = min(end, p[1]);
            } else {
                ++overlap;
                end = p[1];
            }
        }
        return overlap;
    }
};