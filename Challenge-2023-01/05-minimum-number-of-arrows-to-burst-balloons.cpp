#include "../header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        int res = 1;
        int lastEnd = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            auto p = points[i];
            if (p[0] > lastEnd) {
                ++res;
                lastEnd = p[1];
            }
        }
        return res;
    }
};