#include "../header.h"

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (grid[0][i] > grid[0][i-1]) {
                dp[0][i] = (dp[0][i-1] >= 0 ? (dp[0][i-1] + 1) : -1);
            }
            if (grid[0][i] > grid[1][i-1]) {
                dp[0][i] = max(dp[0][i], (dp[1][i-1] >= 0 ? (dp[1][i-1] + 1) : -1));
            }
            res = max(res, dp[0][i]);
            for (int j = 1; j < m - 1; j++) {
                if (grid[j][i] > grid[j-1][i-1]) {
                    dp[j][i] = (dp[j-1][i-1] >= 0 ? (dp[j-1][i-1] + 1) : -1);
                }
                if (grid[j][i] > grid[j][i-1]) {
                    dp[j][i] = max(dp[j][i], (dp[j][i-1] >= 0 ? (dp[j][i-1] + 1) : -1));
                }
                if (grid[j][i] > grid[j+1][i-1]) {
                    dp[j][i] = max(dp[j][i], (dp[j+1][i-1] >= 0 ? (dp[j+1][i-1] + 1) : -1));
                }
                res = max(res, dp[j][i]);
            }
            if (grid[m-1][i] > grid[m-1][i-1]) {
                dp[m-1][i] = (dp[m-1][i-1] >= 0 ? (dp[m-1][i-1] + 1) : -1);
            }
            if (grid[m-1][i] > grid[m-2][i-1]) {
                dp[m-1][i] = max(dp[m-1][i], (dp[m-2][i-1] >= 0 ? (dp[m-2][i-1] + 1) : -1));
            }
        }
        return res;
    }
};