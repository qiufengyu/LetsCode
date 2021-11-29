#include "../header.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size();
        int m = (l + h) / 2;
        while (l < h) {
            m = (l + h) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return (l + h) / 2;
    }
};