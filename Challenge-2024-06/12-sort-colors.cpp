#include "../header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i0 = 0, i2 = n - 1;
        while (i0 < i2 && i0 < n && i2 >= 0) {
            while (i0 < n && nums[i0] != 2) {
                i0++;
            }
            while (i2 >= 0 && nums[i2] == 2) {
                i2--;
            }
            if (i0 < i2 && i0 < n && i2 >= 0) {
                swap(nums[i0], nums[i2]);
            }
        }
        i0 = 0;
        while (i0 < i2 && i0 < n && i2 >= 0) {
            while (i0 < n && nums[i0] != 1) {
                i0++;
            }
            while (i2 >= 0 && nums[i2] == 1) {
                i2--;
            }
            if (i0 < i2 && i0 < n && i2 >= 0) {
                swap(nums[i0], nums[i2]);
            }
        }
    }
};