#include "../header.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int np = prices.size();
        if (np == 0) {
            return 0;
        }
        if (k > np / 2) {
            return maxProfitNoLimit(prices);
        }
        vector<vector<int>>dp(k+1, vector<int>(np, 0));
        for (int i = 1; i <= k; i++) {
            int profit = 0 - prices[0];
            for (int j = 1; j < np; j++) {
                dp[i][j] = max(dp[i][j-1], profit+prices[j]);
                profit = max(profit, dp[i-1][j-1] - prices[j]);
            }
        }
        return dp[k][np-1];
    }
    
    int maxProfitNoLimit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
