#include "../header.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = nums[0], nxt = start + 1, res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nxt) {
                nxt = nums[i] + 1;
            } else {
                res += (nxt - nums[i]);
                nxt++;
            }
        }
        return res;
    }
};