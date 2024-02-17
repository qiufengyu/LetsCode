#include "../header.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n == 2) {
            return true;
        }
        auto p1 = coordinates[0], p2 = coordinates[1];
        if (p1[0] == p2[0]) {
            // to check all points having x == p1[0]
            for (int i = 2; i < n; ++i) {
                if (coordinates[i][0] != p1[0]) {
                    return false;
                }
            }
            return true;
        } else {
            double k = (double)(p1[1] - p2[1]) / (double)(p1[0] - p2[0]);
            double b = p1[1] - k * p1[0];
            for (int i = 2; i < n; ++i) {
                if (abs(coordinates[i][0] * k + b - coordinates[i][1]) > 1e-6) {
                    return false;
                }
            }
            return true;
        }
    }
};