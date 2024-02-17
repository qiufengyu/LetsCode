#include "../header.h"

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> tmp(n, INT_MAX), res(n);
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(tmp.begin(), tmp.end(), obstacles[i]);
            *it = obstacles[i];
            res[i] = 1 + (int)(it - tmp.begin());
        }
        return res;
    }
};