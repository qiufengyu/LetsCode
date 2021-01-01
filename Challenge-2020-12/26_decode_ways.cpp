#include "../header.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int len = s.length();
        if (len == 1) {
            return 1;
        }
        // len > 2
        int dp1 = 1, dp2 = 1;
        int index = 1;
        int res = 0;
        while (index < len) {
            if (s[index] == '0') {
                if (s[index-1] == '1' || s[index-1] == '2') {
                    res = dp2;
                    dp1 = res;
                    dp2 = 0;
                } else {
                    return 0;
                }
            } else if (s[index] <= '6') {
                if (s[index-1] == '1' || s[index-1] == '2') {
                    res = dp1 + dp2;
                    dp2 = dp1;
                    dp1 = res;
                } else {
                    res = dp1;
                    dp2 = dp1;
                }
            } else {
                if (s[index-1] == '1') {
                    res = dp1 + dp2;
                    dp2 = dp1;
                    dp1 = res;
                } else {
                    res = dp1;
                    dp2 = 0;
                }
            }
            index++;
        }        
        return res;
    }
};

