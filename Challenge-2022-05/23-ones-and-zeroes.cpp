#include "../header.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zeros = 0, ones = 0;
        for (auto &str: strs) {
            for (char &c: str) {
                if (c == '0') {
                    ++zeros;
                } else {
                    ++ones;
                }
            }
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
            zeros = 0;
            ones = 0;
        }
        return dp[m][n];
    }
};