#include "../header.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, lp = 0, rp = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            rp += (1 - nums[i]);
            while (lp < rp - k) {
                lp += 1 - nums[l];
                ++l;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};