#include "../header.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }   
};