#include "../header.h"

class Solution {
public:
    int countVowelStrings(int n) {
        int dp0[5] = {0, 0, 0, 0, 0};
        int dp1[5] = {1, 1, 1, 1, 1};
        int i = 2;
        while (i <= n) {
            if (i & 1) {
                dp1[0] = dp0[0];
                dp1[1] = dp0[0] + dp0[1];
                dp1[2] = dp0[0] + dp0[1] + dp0[2];
                dp1[3] = dp0[0] + dp0[1] + dp0[2] + dp0[3];
                dp1[4] = dp0[0] + dp0[1] + dp0[2] + dp0[3] + dp0[4];
            } else {
                dp0[0] = dp1[0];
                dp0[1] = dp1[0] + dp1[1];
                dp0[2] = dp1[0] + dp1[1] + dp1[2];
                dp0[3] = dp1[0] + dp1[1] + dp1[2] + dp1[3];
                dp0[4] = dp1[0] + dp1[1] + dp1[2] + dp1[3] + dp1[4];
            }
            i++;
        }
        if (n & 1) {
            return dp1[0] + dp1[1] + dp1[2] + dp1[3] + dp1[4];
        } else {            
            return dp0[0] + dp0[1] + dp0[2] + dp0[3] + dp0[4];
        }
    }
};
