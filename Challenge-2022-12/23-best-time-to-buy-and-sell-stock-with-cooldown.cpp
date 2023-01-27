#include "../header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1, 0), sell(n+1, 0);
        buy[0] = -prices[0];
        for (int i = 0; i < n; ++i) {
            int p = prices[i];
            buy[i+1] = max(buy[i], -p + (i == 0 ? 0 : sell[i-1]));
            sell[i+1] = max(sell[i], buy[i] + p);
        }
        return sell[n];
    }
};