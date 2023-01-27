#include "../header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, count = 0;
        while (j < nums.size()) {
            if (nums[j] == nums[i]) {
                ++count;
            } else {
                ++i;
                nums[i] = nums[j];
            }
            ++j;
        }
        return nums.size() - count;
    }
};