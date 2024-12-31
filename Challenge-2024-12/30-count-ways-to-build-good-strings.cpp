#include "../header.h"

const int M = 1000000007;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, 0LL);
        dp[0] = 1LL;
        for (int i = 0; i <= high; i++) {
            if (i - zero >= 0) {
                dp[i] += dp[i - zero];
                dp[i] %= M;
            }
            if (i - one >= 0) {
                dp[i] += dp[i - one];
                dp[i] %= M;
            }
        }
        long long res = 0LL;
        for (int i = low; i <= high; i++) {
            res += dp[i];
            res %= M;
        }
        return (int)res;
    }
};