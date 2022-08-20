#include "../header.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // dp1: last increase, dp2: last decrese
        vector<int> dp1(n, 1), dp2(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                dp1[i] = dp2[i-1] + 1;
                dp2[i] = dp2[i-1];
            } else if (nums[i] < nums[i-1]) {
                dp2[i] = dp1[i-1] + 1;
                dp1[i] = dp1[i-1];
            } else {
                dp1[i] = dp1[i-1];
                dp2[i] = dp2[i-1];
            }
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};