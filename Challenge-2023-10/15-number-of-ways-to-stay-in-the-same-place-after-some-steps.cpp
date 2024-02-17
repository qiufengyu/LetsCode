#include "../header.h"

class Solution {
public:
    int numWays(int steps, int arrLen) {
        // to avoid TLE, because some positions will never be reached
        int maxPosition = min(steps / 2 + 1, arrLen);
        vector<int> dp1(maxPosition, 0), dp2(maxPosition, 0);
        if (arrLen == 1) {
            return 1;
        }
        int const M = 1000000007;
        dp1[0] = 1;
        for (int i = 0; i < steps; i++) {
            dp2[0] = (dp1[1] + dp1[0]) % M;
            dp2[maxPosition-1] = (dp1[maxPosition-1] + dp1[maxPosition-2]) % M;
            for (int j = 1; j < maxPosition - 1; j++) {
                dp2[j] = ((dp1[j-1] + dp1[j]) % M + dp1[j+1]) % M;
            }
            swap(dp1, dp2);
        }
        return dp1.front();
    }
};