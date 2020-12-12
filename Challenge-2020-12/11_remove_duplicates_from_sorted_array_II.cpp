#include "../header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0, current = 1;
        int count = 0;
        if (nums.empty()) {
            return 0;
        }
        while (current < nums.size()) {
            if (nums[prev] == nums[current] && count == 1) {
                current++;
            }
            else {
                if (nums[prev] == nums[current]) {
                    count++;
                } else {
                    count = 0;
                }
                nums[++prev] = nums[current++];
            }
        }
        return prev + 1;
    }
};