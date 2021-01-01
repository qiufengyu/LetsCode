#include "../header.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+2, vector<int>(n+2, -1)));
        dp[0][1][n] = grid[0][0] + grid[0][n-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    int current = grid[i][j-1] + (j != k) * grid[i][k-1];
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (dp[i-1][j+x][k+y] != -1)
                                dp[i][j][k] = max(0, max(dp[i][j][k], current + dp[i-1][j+x][k+y]));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans = max(ans, dp[m-1][j][k]);
            }
        }
        return ans;
    }
};
