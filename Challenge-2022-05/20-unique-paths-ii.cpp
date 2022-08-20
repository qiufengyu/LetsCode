#include "../header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1- obstacleGrid[0][0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = obstacleGrid[0][i] == 0 ? dp[0][i-1] : 0;
        }
        for (int j = 1; j < m; ++j) {
            dp[j][0] = obstacleGrid[j][0] == 0 ? dp[j-1][0] : 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];        
    }
};