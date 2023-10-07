#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(k, vector<long>(m, 0)));
        for (int i = 0; i < m; i++) {
            dp[0][0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int c = 0; c < min(i+1, k); c++) {
                for (int mx = 0; mx < m; mx++) {
                    dp[i][c][mx] = (dp[i][c][mx] + (mx+1)*dp[i-1][c][mx]) % M;
                    if (c != 0) {
                        long sum = 0;
                        for (int pm = 0; pm < mx; pm++) {
                            sum += dp[i-1][c-1][pm];
                            sum %= M;
                        }
                        dp[i][c][mx] = (dp[i][c][mx] + sum) % M;
                    }
                }
            }
        }
        long res = 0;
        for (int mx = 0; mx < m; mx++) {
            res += dp[n-1][k-1][mx];
            res %= M;
        }
        return (int)res;
    }
};