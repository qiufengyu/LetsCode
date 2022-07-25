#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) {
            return 1;
        }
        if (k > n * (n-1) / 2) {
            return 0;
        }
        vector<vector<long>> dp(n+1, vector<long>(k+1, 0));
        dp[2][0] = 1;
        dp[2][1] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i * (i-1) / 2); ++j) {
               dp[i][j] = (dp[i][j-1]  + dp[i-1][j]) % M;
               if (j >= i) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + M) % M;
               }
            }            
        }
        return (int)(dp[n][k]);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    cout << Solution().kInversePairs(n, k) << endl;
    return 0;
}