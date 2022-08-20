#include "../header.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, end = 0;
        // don't care dp[n-1][n-1], since it is not used for other cases
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i] = true;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                end = i + 1;
            }
        }
        for (int l = 2; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                if (s[i] == s[i+l] && dp[i+1][i+l-1]) {
                    dp[i][i+l] = true;
                    if (l > end - start) {
                        start = i;
                        end = l + i;
                    }                    
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};