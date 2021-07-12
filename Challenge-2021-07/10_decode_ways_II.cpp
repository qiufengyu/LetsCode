#include "../header.h"

constexpr int M = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        long dp1 = 1, dp2 = count1(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            long dp3 = dp2 * count1(s[i]) + dp1 * count2(s[i-1], s[i]);
            dp3 %= M;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp2;
    }

    int count1(char c) {
        if (c == '0') {
            return 0;
        }
        if (c == '*') {
            return 9;
        }
        return 1;
    }

    int count2(char c1, char c2) {
        if (c1 == '*' && c2 == '*') {
            return 15;
        }
        if (c1 == '*') {
            if (c2 >= '0' && c2 <= '6') {
                return 2;
            }
            return 1;
        }
        if (c2 == '*') {
            if (c1 == '1') {
                return 9;
            } else if (c1 == '2') {
                return 6;
            }
            return 0;
        }
        int prefix = (c1 - '0') * 10 + (c2 - '0');
        if (prefix >= 10 && prefix <= 26) {
            return 1;
        }
        return 0;
    }
};