#include "../header.h"

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        size_t n = nums.size();
        int i = 0;
        while (i < n && nums[i] == nums[0]) {
            i++;
        }
        if (i == n) {
            return true;
        }
        if (nums[i] > nums[0]) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j-1]) {
                    return false;
                }
            }
        } else {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};