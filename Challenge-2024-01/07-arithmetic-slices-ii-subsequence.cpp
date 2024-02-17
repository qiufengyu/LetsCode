#include "../header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<map<long, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)nums[i] - nums[j];
                int tmp = dp[j].count(d) ? dp[j][d] : 0;
                dp[i][d] += (1 + tmp);
                res += tmp;
            }
        }
        return res;
    }
};