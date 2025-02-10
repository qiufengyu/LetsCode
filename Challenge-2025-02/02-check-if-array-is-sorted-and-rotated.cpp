#include "../header.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        int down = 0;
        if (nums.back() > nums.front()) {
            down++;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                down++;
            }
        }
        return down <= 1;
    }
};