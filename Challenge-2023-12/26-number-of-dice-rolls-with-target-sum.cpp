#include "../header.h"

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        int const M = 1000000007;
        for (int j = 1; j <= target && j <= k; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int x = 1; x <= k; x++) {
                    if (j - x > 0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % M;
                    }
                }
            }
        }
        return dp[n][target];
    }
};

int main() {
    int n = 30, k = 30, target = 500;
    cout << Solution().numRollsToTarget(n, k, target) << endl;
    return 0;
}