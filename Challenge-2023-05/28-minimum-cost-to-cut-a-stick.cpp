#include "../header.h"

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int l = 2; l < m; ++l) {
            for (int left = 0; left < m - l; ++left) {
                int right = left + l;
                int res = INT_MAX;
                for (int i = left + 1; i < right; ++i) {
                    res = min(res, dp[left][i] + dp[i][right] + cuts[right] - cuts[left]);
                }
                dp[left][right] = res;
            }
        }
        return dp[0][m-1];
    }
};