#include "../header.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, current = 0, i = 0;
        while (current < nums.size() - 1) {
            ++res;
            int prev = current;
            while (i <= prev) {
                current = max(current, nums[i] + i);
                ++i;
            }
            // there is always a solution
        }
        return res;
    }
};