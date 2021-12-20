#include "../header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 0) {
            int target = sum / 2;
            vector<bool> dp(target + 1, false);
            dp[0] = true;
            for (int const& num: nums) {
                for (int i = target; i >= 0; --i) {
                    if (dp[i] && i + num <= target) {
                        dp[i + num] = true;
                    }
                }
                if (dp[target]) {
                    return true;
                }
            }
        }
        return false;
    }
};