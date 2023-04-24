#include "../header.h"

class Solution {
public:
    int minInsertions(string s) {
        string s1{s};
        reverse(s1.begin(), s1.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return n - dp[n][n];
    }

    void lcs(string& s1, string& s2, int n1, int n2, vector<vector<int>>& dp) {
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
};
