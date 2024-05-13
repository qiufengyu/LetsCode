#include "../header.h"

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(ring, 0, key, 0, dp) + key.size();
    }

    int helper(string ring, int ri, string key, int ki, vector<vector<int>>& dp) {
        if (ki == key.size()) {
            return 0;
        }
        if (dp[ri][ki] != -1) {
            return dp[ri][ki];
        }
        int res = INT_MAX;
        for (int i = 0; i < ring.size(); i++) {
            if (ring[i] == key[ki]) {
                int step1 = abs(i - ri);
                int step2 = ring.size() - step1;
                int minStep = min(step1, step2);
                minStep += helper(ring, i, key, ki+1, dp);
                res = min(minStep, res);
            }
        }
        return dp[ri][ki] = res;
    }
};
