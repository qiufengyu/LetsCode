#include "../header.h"

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> sufSum(n, 0);
        sufSum[n-1] = piles[n-1];
        for (int i = n - 2; i >= 0; i--) {
            sufSum[i] = piles[i] + sufSum[i+1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = sufSum[i];
                } else {
                    for (int k = 1; k <= 2 * m; k++) {
                        dp[i][m] = max(dp[i][m], sufSum[i] - dp[i+k][max(m, k)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};