#include "../header.h"

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return dfs(0, k, n, dp, piles);
    }

    int dfs(int i, int j, int n, vector<vector<int>>& dp, vector<vector<int>>& piles) {
        if (i == n || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // from i + 1 to 0
        // not take from i-th pile
        int res = dfs(i+1, j, n, dp, piles);
        int val = 0;
        for (int l = 0; l < min((int)piles[i].size(), j); ++l) {
            val += piles[i][l];
            res = max(res, val + dfs(i+1, j - 1 - l, n, dp, piles));
        }
        dp[i][j] = res;
        return res;
    }
};