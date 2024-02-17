#include "../header.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k;
        int mn = nums[k];
        int res = mn;
        while (l > 0 || r < nums.size() - 1) {
            if (l <= 0 || (r < nums.size() - 1 && nums[r+1] > nums[l-1])) {
                r++;
            } else {
                l--;
            }
            mn = min(mn, min(nums[l], nums[r]));
            res = max(res, mn * (r - l + 1));
        }
        return res;
    }
};