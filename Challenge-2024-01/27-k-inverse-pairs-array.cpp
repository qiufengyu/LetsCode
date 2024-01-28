#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int res = 0;
                for (int l = 0; l < min(i, j+1); l++) {
                    res = (res + dp[i - 1][j - l]) % M;
                }
                dp[i][j] = res;
            }            
        }
        return dp[n][k];
    }
    
};