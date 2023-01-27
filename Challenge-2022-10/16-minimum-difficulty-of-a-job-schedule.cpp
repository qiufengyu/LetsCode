#include "../header.h"

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        int maxDiff = 0;
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i+1], jobDifficulty[i]);
        }        
        for (int day = 2; day <= d; ++day) {
            for (int i = 0; i <= n - day; ++i) {
                maxDiff = 0;
                dp[i] = INT_MAX;
                for (int j = i; j <= n - day; ++j) {
                    maxDiff = max(maxDiff, jobDifficulty[j]);
                    dp[i] = min(dp[i], maxDiff + dp[j+1]);
                }
            }
        }
        return dp[0];        
    }
};