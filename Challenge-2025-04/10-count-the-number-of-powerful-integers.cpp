#include "../header.h"

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        auto countPowerfulUpTo = [&](long long num) -> long long {
            string numStr = to_string(num);
            int suffixLen = s.size();
            int prefixLen = numStr.size() - suffixLen;

            if (prefixLen < 0) return 0;

            vector<vector<long long>> dp(prefixLen + 1, vector<long long>(2, 0LL));

            dp[prefixLen][0] = 1;
            string suffixFromNum = numStr.substr(prefixLen);
            dp[prefixLen][1] = stoll(suffixFromNum) >= stoll(s) ? 1LL : 0LL;

            for (int i = prefixLen - 1; i >= 0; --i) {
                int digit = numStr[i] - '0';
                dp[i][0] = (limit + 1) * dp[i + 1][0];

                if (digit <= limit) {
                    dp[i][1] = digit * dp[i + 1][0] + dp[i + 1][1];
                } else {
                    dp[i][1] = (limit + 1) * dp[i + 1][0];
                }
            }

            return dp[0][1];
        };

        return countPowerfulUpTo(finish) - countPowerfulUpTo(start - 1);
    }
};