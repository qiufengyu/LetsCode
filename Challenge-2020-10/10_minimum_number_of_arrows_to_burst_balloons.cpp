#include "../header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return false;
        });
        int ans = 1, end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            auto p = points[i];
            if (p[0] <= end) {
                end = min(end, p[1]);
            } else {
                ans++;
                end = p[1];
            }
        }
        return ans;
    }
};