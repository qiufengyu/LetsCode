#include "../header.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int minN = INT_MAX;
        for (int i = 0; i < n; i++) {
            minN = min(minN, nums[i]);
            if (minN == nums[i]) {
                continue;
            }
            for (int j = n - 1; j > i; j--) {
                if (minN < nums[j] && nums[i] > nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};