#include "../header.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), idx = 0;
        vector<int> dp(n, 0), prev(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > dp[idx]) {
                idx = i;
            }
        }
        vector<int> res;
        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = prev[idx];
        }
        return res;
    }
};