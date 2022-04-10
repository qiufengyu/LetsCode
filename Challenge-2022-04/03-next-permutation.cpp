#include "../header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, j = nums.size() - 2;
        while (j >= 0) {
            if (nums[j] < nums[j + 1]) {
                break;
            }
            j--;
        }
        if (j < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            while (nums[i] <= nums[j]) {
                i--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + j + 1, nums.end());
        }
    }
};