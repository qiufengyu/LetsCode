#include "../header.h"

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(d, 0));
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], jobDifficulty[i]);
        }
        for (int dd = 1; dd < d; dd++) {
            for (int i = dd; i < n; i++) {
                int lm = jobDifficulty[i];
                dp[i][dd] = INT_MAX;
                for (int j = i; j >= dd; j--) {
                    lm = max(lm, jobDifficulty[j]);
                    dp[i][dd] = min(dp[i][dd], dp[j-1][dd-1] + lm);
                }
            }
        }
        return dp[n-1][d-1];
    }
};