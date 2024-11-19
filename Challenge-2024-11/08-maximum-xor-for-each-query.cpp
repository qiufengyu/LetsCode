#include "../header.h"

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int M = ((1 << maximumBit) - 1);
        vector<int> res(nums.size(), 0);
        int n = nums.size(), x = 0;
        for (int i = 0; i < n; i++) {
            x = x ^ nums[i];
            res[n - 1 - i] = M ^ (x);
        }
        return res;
    }
};