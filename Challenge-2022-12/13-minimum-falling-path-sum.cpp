#include "../header.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) {
            return matrix[0][0];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = matrix[i][0] + min(dp[i-1][0], dp[i-1][1]);
            for (int j = 1; j < n - 1; ++j) {
                dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
            }
            dp[i][n-1] = matrix[i][n-1] + min(dp[i-1][n-2], dp[i-1][n-1]); // n >= 2!
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};