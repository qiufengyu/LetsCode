#include "../header.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        for (auto day: days) {
            dp[day] = 0;
        }
        dp[0] = 0;
        for (int d = 1; d < 366 && d <= days.back(); ++d) {
            if (dp[d] == -1) {
                dp[d] = dp[d-1];
            } else {
                int t = costs[0] + dp[d-1];
                t = min(t, costs[1] + dp[max(d-7, 0)]);
                t = min(t, costs[2] + dp[max(d-30, 0)]);
                dp[d] = t;
            }
        }
        return dp[days.back()];
    }
};