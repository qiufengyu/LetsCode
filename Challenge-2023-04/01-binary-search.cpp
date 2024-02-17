#include "../header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int m = l + (h - l) / 2;
        while (l <= h) {
            m = l + (h - l) / 2;
            if (target == nums[m]) {
                return m;
            } else if (target > nums[m]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        if (target == nums[m]) {
            return m;
        }
        return -1;
    }
};