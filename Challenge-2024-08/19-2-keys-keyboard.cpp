#include "../header.h"

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
        }
        for (int i = 2; i * 2 <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                dp[i * j] = min(dp[i * j], dp[i] + j);
            }
        }
        return dp[n];
    }
};