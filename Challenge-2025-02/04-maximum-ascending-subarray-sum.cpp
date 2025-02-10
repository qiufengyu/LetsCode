#include "../header.h"

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], s = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                s += nums[i];
            } else {
                s = nums[i];
            }
            res = max(s, res);
        }
        return res;
    }
};