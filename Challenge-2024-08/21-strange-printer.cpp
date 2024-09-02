#include "../header.h"

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + 1;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        int tmp = dp[i][k] + dp[k+1][j-1];
                        if (k + 1 > j - 1) {
                            tmp = dp[i][k];
                        }
                        dp[i][j] = min(dp[i][j], tmp);
                    }                    
                }
            }
        }
        return dp[0][n-1];
    }
};