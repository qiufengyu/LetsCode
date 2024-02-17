#include "../header.h"

int const M = 1000000007;

class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int current, const int m, const int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || current >= grid[i][j]) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int top = dfs(grid, i - 1, j, dp, grid[i][j], m, n);
        int bottom = dfs(grid, i + 1, j, dp, grid[i][j], m, n);
        int left = dfs(grid, i, j - 1, dp, grid[i][j], m, n);
        int right = dfs(grid, i, j + 1, dp, grid[i][j], m, n);
        dp[i][j] = (1 + top + bottom + left + right) % M;
        return dp[i][j];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == -1) {
                    res = ((res + dfs(grid, i, j, dp, -1, m, n)) % M);
                } else {
                    res = ((res + dp[i][j]) % M);
                }
            }
        }
        return res;
    }
};