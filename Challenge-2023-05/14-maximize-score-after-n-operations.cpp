#include "../header.h"

class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& dp, int state, int current) {
        if (current == 0) {
            return 0;
        }
        if (dp[state] != 0) {
            return dp[state];
        }
        int res = 0, n = nums.size();
        vector<int> total;
        for (int i = 0; i < n; ++i) {
            if (state & (1 << i)) {
                total.push_back(i);
            }
        }
        for (int i = 0; i < total.size(); ++i) {
            for (int j = i + 1; j < total.size(); ++j) {
                res = max(res, __gcd(nums[total[i]], nums[total[j]]) * current + dfs(nums, dp, state & (~(1 << total[i]) & (~(1 << total[j]))), current - 1));
            }
        }
        dp[state] = res;
        return res;
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14, 0);
        return dfs(nums, dp, (1 << nums.size()) - 1, nums.size() / 2);
    }
};