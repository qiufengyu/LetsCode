#include "../header.h"

class Solution {
  vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, const int m, const int n) {
    if (dp[i][j]) {
      return dp[i][j];
    }
    int mx = 1;
    for (int t = 0; t < 4; ++t) {
      int x = i + directions[t][0];
      int y = j + directions[t][1];
      if (x >= 0 && y >= 0 && x < m && y < n && matrix[i][j] < matrix[x][y]) {
        int len = 1 + dfs(matrix, dp, x, y, m, n);
        mx = max(mx, len);
      }
    }
    dp[i][j] = mx;
    return mx;
  }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
          return 0;
        }
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            res = max(res, dfs(matrix, dp, i, j, m, n));
          }
        }
        return res;
    }
};