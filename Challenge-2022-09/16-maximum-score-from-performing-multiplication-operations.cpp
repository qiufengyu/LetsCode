#include "../header.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        return helper(0, 0, nums, multipliers, dp, m, n);
    }

    int helper(int l, int i, vector<int>& nums, vector<int>& multipliers,
               vector<vector<int>>& dp, int m, int n) {
        if (i == m) {
            return 0;
        }
        if (dp[l][i] != INT_MIN) {
            return dp[l][i];
        }
        int pickLeft = helper(l+1, i+1, nums, multipliers, dp, m, n) + multipliers[i] * nums[l];
        int pickRight = helper(l, i+1, nums, multipliers, dp, m, n) + multipliers[i] * nums[n-(i-l)-1];
        dp[l][i] = max(pickLeft, pickRight);
        return dp[l][i];
    }
};