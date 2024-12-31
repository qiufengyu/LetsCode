#include "../header.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        helper(nums, target, 0, 0, nums.size(), res);
        return res;
    }

    void helper(vector<int>& nums, int target, int s, int index, const size_t n, int& res) {
        if (index == n) {
            if (s == target) {
                res += 1;
            }
            return;
        }
        helper(nums, target, s + nums[index], index + 1, n, res);
        helper(nums, target, s - nums[index], index + 1, n, res);
    }
};