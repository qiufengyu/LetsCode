#include "../header.h"

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0LL));
        for (int i = 0; i < n; i++) {
            dp[0][i] = points[0][i];
        }
        for (int i = 1; i < m; i++) {
            vector<long long> left(n, 0LL), right(n, 0LL);
            left[0] = dp[i-1][0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j-1]-1, dp[i-1][j]);
            }
            right[n-1] = dp[i-1][n-1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j+1]-1, dp[i-1][j]);
            }
            for (int j = 0; j < n; j++) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }
        }
        return *max_element(dp[m-1].begin(), dp[m-1].end());
    }
};