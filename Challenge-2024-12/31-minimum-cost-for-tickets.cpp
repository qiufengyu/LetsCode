#include "../header.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        dp[0] = 0;
        int id = 0;
        for (int i = 1; i < 366; i++) {
            dp[i] = dp[i-1];
            if (id < days.size() && days[id] == i) {
                int cost = dp[i-1] + costs[0];
                if (i - 7 >= 0) {
                    cost = min(cost, dp[i-7] + costs[1]);
                } else {
                    cost = min(cost, costs[1]);
                }
                if (i - 30 >= 0) {
                    cost = min(cost, dp[i-30] + costs[2]);
                } else {
                    cost = min(cost, costs[2]);
                }
                dp[i] = cost;
                id++;
            } else if (id >= days.size()) {
                break;
            }
        }
        return dp[days.back()];
    }
};