#include "../header.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        dp[0] = 1;
        int l = 1, index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > l) {
                l = dp[i];
                index = i;
            }
        }
        vector<int> res;
        int prev = nums[index];
        for (int i = index; i >= 0 && l > 0; --i) {
            if (dp[i] == l && prev % nums[i] == 0) {
                --l;
                prev = nums[i];
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};