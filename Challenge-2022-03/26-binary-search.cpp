#include "../header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int m = (i + j) / 2;
        while (i <= j) {             
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                i = m + 1;
            } else {
                j = m - 1;
            }
            m = (i + j) / 2;
        }
        return nums[m] == target ? m : -1;
    }
};