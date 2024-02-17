#include "../header.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < nums.size() && nums[l] % 2 == 0) {
                l++;
            }
            while (r >= 0 && nums[r] % 2 != 0) {
                r--;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};