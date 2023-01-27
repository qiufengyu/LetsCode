#include "../header.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int i = 0; i < m; ++i) {
            if (i > 0) {
                dp[i][0] = max(dp[i-1][0], text1[i] == text2[0] ? 1 : 0);
            }
            for (int j = 1; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = i > 0 ? (dp[i-1][j-1] + 1) : 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], i > 0 ? dp[i-1][j] : 0);
                }
            }
        }
        return dp[m-1][n-1];
    }
};