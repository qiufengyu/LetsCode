#include "../header.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
