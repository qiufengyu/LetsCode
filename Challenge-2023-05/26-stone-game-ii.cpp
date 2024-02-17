#include "../header.h"

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = piles[n-1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = piles[i] + suffixSum[i+1];
        }
        return helper(piles, dp, suffixSum, 0, 1);
    }

    int helper(vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffixSum, int i, int M) {
        if (i == piles.size()) {
            return 0;
        }
        if (i + 2 * M >= piles.size()) {
            return suffixSum[i];
        }
        if (dp[i][M] != 0) {
            return dp[i][M];
        }
        int res = 0;
        for (int x = 1; x <= 2 * M; ++x) {
            res = max(res, suffixSum[i] - helper(piles, dp, suffixSum, i + x, max(M, x)));
        }
        dp[i][M] = res;
        return res;
    }
};