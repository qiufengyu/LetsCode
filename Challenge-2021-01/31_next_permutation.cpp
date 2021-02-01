#include "../header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int i = sz - 2, j = sz - 1;
        while (i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        // if i < 0, then reverse the array
        if (i >= 0) {
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }        
        reverse(nums.begin() + i + 1, nums.end());
    }
};
