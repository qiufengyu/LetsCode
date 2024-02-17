#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return helper(dp, n, minProfit, group, profit, 0, 0, 0);        
    }

    int helper(vector<vector<vector<int>>>& dp, int n, int minProfit, vector<int>& group, vector<int>& profit, int i, int j, int k) {
        if (i == group.size()) {
            return k >= minProfit;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int t = helper(dp, n, minProfit, group, profit, i+1, j, k);
        if (j + group[i] <= n) {
            t += helper(dp, n, minProfit, group, profit, i + 1, j + group[i], min(minProfit, k + profit[i]));
        }
        dp[i][j][k] = t % M;
        return dp[i][j][k];
    }
};