#include "../header.h"

const int M = 1000000007;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].length();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                freq[j][words[i][j] - 'a'] += 1;
            }
        }
        vector<vector<long>> dp(n+1, vector<long>(target.length() + 1, 0L));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target.length(); ++j) {
                long cnt = (long)freq[i-1][target[j-1] - 'a'];
                dp[i][j] = ((long)dp[i-1][j] + cnt * dp[i-1][j-1] % M) % M;
            }
        }
        return (int)dp[n][target.length()];
    }
};