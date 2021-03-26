#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp0 = 0, dp1 = -prices[0];
        for (int p: prices) {
            int temp = dp0;
            dp0 = max(dp0, dp1 + p - fee);
            dp1 = max(dp1, temp - p);            
        }
        return dp0;
    }
};