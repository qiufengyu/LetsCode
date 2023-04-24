#include "../header.h"

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            long long cur = 0LL, cnt = 0LL;
            for (int j = i; j < n; ++j) {
                int d = s[j] - '0';
                cur = 10 * cur + d;
                if (cur < 1 || cur > k) {
                    break;
                }
                int nCount = dp[j+1];
                cnt = (cnt + nCount) % 1000000007;
            }
            dp[i] = cnt;
        }
        return dp[0];
    }
};