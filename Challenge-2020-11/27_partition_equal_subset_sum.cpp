#include "../header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp (target + 1, false);
        dp[0] = true;
        for (auto x: nums) {
            for (int i = target; i >= 0; i--) {
                if (dp[i] && i + x <= target) {
                    dp[i + x] = true; // i + x will only be used in next round
                }
            }
            if (dp[target]) {
                return true;
            }
        }
        return false;
    }
};