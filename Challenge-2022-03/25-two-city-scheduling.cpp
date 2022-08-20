#include "../header.h"

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> v(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += costs[i][0];
            v[i] = costs[i][1] - costs[i][0];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n / 2; ++i) {
            res += v[i];
        }
        return res;
    }
};