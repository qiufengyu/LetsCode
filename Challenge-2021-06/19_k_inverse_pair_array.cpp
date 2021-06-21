#include "../header.h"

const int M = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 1; i <= n; ++i) {
          for (int j = 0; j <=k && j <= i * (i-1) / 2; ++j) {
            if (i == 1 && j== 0) {
              dp[i][j] = 1;
              break;
            } else if (j == 0) {
              dp[i][j] = 1;
            } else {
              int temp = (dp[i-1][j] - ((j - i >= 0 )? dp[i-1][j-i] : 0) + M) % M;
              dp[i][j] = (dp[i][j-1] + temp) % M;
            }
          }
        }
        return dp[n][k];
    }
};