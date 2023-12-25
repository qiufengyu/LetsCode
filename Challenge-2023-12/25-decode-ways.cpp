#include "../header.h"

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            char x = s[i-1];
            if (x == '0') {
                if (s[i-2] == '1' || s[i-2] == '2') {
                    dp[i] += dp[i-2];
                } else {
                    return 0;
                }
            } else if (x >= '1' && x <= '6') {
                if (s[i-2] == '1' || s[i-2] == '2') {
                    dp[i] += dp[i-2];
                }
                dp[i] += dp[i-1];
            } else {
                if (s[i-2] == '1') {
                    dp[i] += dp[i-2];
                }
                dp[i] += dp[i-1];
            }
        }
        return dp[n];
    }
};