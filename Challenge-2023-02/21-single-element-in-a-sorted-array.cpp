#include "../header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size(), m = l + (r - l) / 2;
        if (r == 1) {
            return nums[0];
        }
        while (l < r) {
            m = l + (r - l) / 2;
            if (m % 2 == 0) {
                if (nums[m] == nums[m+1]) {
                    l = m + 2;
                } else if (nums[m] == nums[m-1]) {
                    r = m - 2;
                } else {
                    return nums[m];
                }
            } else {
                if (nums[m] == nums[m+1]) {
                    r = m - 1;
                } else if (nums[m] == nums[m-1]) {
                    l = m + 1;
                } else {
                    return nums[m];
                }
            }
        }
        m = l + (r - l) / 2;
        return nums[m];
    }
};