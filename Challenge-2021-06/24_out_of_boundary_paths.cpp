#include "../header.h"

int const M = 1e9 + 7;
const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[51][51][51];        
        memset(dp, -1, sizeof(dp));
        return f(startRow + 1, startColumn + 1, maxMove, m, n, dp);
    }

    int f(int i, int j, int k, int const m, int const n, int dp[51][51][51]) {
        if (k < 0) {
            return 0;
        }
        if (i < 1 || i > m || j < 1 || j > n) {
            return 1;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        dp[i][j][k] = 0;
        for (int d = 0; d < 4; ++d) {
            int x = i + directions[d][0], y = j + directions[d][1];
            dp[i][j][k] = (dp[i][j][k] + 0LL + f(x, y, k - 1, m, n, dp)) % M;
        }
        return dp[i][j][k];
    }
};
