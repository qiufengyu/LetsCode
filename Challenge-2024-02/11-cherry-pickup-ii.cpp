#include "../header.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        int res = dp[0][0][n-1];
        for (int r = 1; r < m; r++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int mx = -1;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n) {
                                mx = max(mx, dp[r-1][i+x][j+y]);
                            }
                        }
                    }
                    if (mx != -1) {
                        dp[r][i][j] = mx + grid[r][i] + grid[r][j];
                        res = max(res, dp[r][i][j]);
                    }
                    
                }
            }
        }
        return res;
    }
};