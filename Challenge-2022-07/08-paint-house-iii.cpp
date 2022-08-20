#include "../header.h"

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 100000000;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target+1, INF)));
        for (int c = 1; c <= n; ++c) {
            if (houses[0] == c) {
                dp[0][c-1][1] = 0;
            } else if (houses[0] == 0) {
                dp[0][c-1][1] = cost[0][c-1];
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= min(target, i + 1); ++j) {
                for (int c = 1; c <= n; ++c) {
                    if (houses[i] != 0 && houses[i] != c) {
                        continue;
                    }
                    int same = dp[i-1][c-1][j];
                    int diff = INF;
                    for (int c_ = 1; c_ <= n; ++c_) {
                        if (c_ != c) {
                            diff = min(diff, dp[i-1][c_-1][j-1]);
                        }
                    }
                    int paint_cost = cost[i][c-1] * int(houses[i] == 0);
                    dp[i][c-1][j] = min(same, diff) + paint_cost;
                }
            }
        }
        int res = INF;
        for (int c = 0; c < n; ++c) {
            res = min(res, dp[m-1][c][target]);
        }
        return res == INF ? -1 : res;
    }
};