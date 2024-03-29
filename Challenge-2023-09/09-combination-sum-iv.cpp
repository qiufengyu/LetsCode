#include "../header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int ni = 0; ni < nums.size(); ni++) {
                if (nums[ni] <= i) {
                    dp[i] += dp[i-nums[ni]];
                }
            }
        }
        return dp[target];
    }
};