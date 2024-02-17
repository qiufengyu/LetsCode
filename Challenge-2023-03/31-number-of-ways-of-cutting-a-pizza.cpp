#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, -1)));
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        // preSum[i][j] = #apples from pizza[i][j] to the bottom right
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                preSum[i][j] = (pizza[i][j] == 'A') + preSum[i][j+1] + preSum[i+1][j] - preSum[i+1][j+1];
            }
        }
        return helper(dp, preSum, m, n, k - 1, 0, 0);
    }

    int helper(vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum, const int m, const int n, int k, int i, int j) {
        if (preSum[i][j] == 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        if (dp[k][i][j] != -1) {
            return dp[k][i][j];
        }
        long long res = 0;
        // horizontal
        for (int ii = i + 1; ii < m; ++ii) {
            if (preSum[i][j] > preSum[ii][j]) {
                res += (helper(dp, preSum, m, n, k-1, ii, j) % M);
            }
        }
        // vertical
        for (int jj = j + 1; jj < n; ++jj) {
            if (preSum[i][j] > preSum[i][jj]) {
                res += (helper(dp, preSum, m, n, k-1, i, jj) % M);
            }
        }
        res %= M;
        dp[k][i][j] = (int)res;
        return (int)res;
    }
};