#include "../header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> sum(target + 1, 0);
        sum[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] <= i) {
                    sum[i] += sum[i-nums[j]];
                }
            }
        }
        return sum[target];
    }
};