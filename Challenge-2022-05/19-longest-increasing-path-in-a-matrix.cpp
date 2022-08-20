#include "../header.h"

int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = dfs(matrix, i, j, m, n, dp);
                res = max(res, t);
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int mx = 1;
        for (int d = 0; d < 4; ++d) {
            int x = i + directions[d][0], y = j + directions[d][1];
            if (x >= 0 && y >= 0 && x < m && y < n && matrix[i][j] < matrix[x][y]) {
                int t = 1 + dfs(matrix, x, y, m, n, dp);
                mx = max(mx, t);
            }
        }
        dp[i][j] = mx;
        return mx;
    }
};