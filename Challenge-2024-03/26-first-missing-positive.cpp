#include "../header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        while (idx < n) {
            if (nums[idx] != idx + 1 && nums[idx] <= n) {
                if (nums[idx] != nums[nums[idx] - 1]) {
                    swap(nums[idx], nums[nums[idx] - 1]);
                    idx--;
                }
            }
            idx++;
        }
        idx = 0;
        while (idx < n) {
            if (nums[idx] != idx + 1) {
                return idx + 1;
            }
            idx++;
        }
        return n + 1;
    }
};