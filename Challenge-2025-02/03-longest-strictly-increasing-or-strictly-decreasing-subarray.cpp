#include "../header.h"

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int res = 1, len = 1;
        int direction = nums[0] < nums[1] ? 1 : (nums[0] == nums[1] ? 0 : -1);
        if (direction != 0) {
            len = 2;
            res = 2;
        }
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                if (direction == -1) {
                    len++;
                } else {
                    len = 2;
                }
                direction = -1;
            } else if (nums[i] < nums[i+1]) {
                if (direction == 1) {
                    len++;
                } else {
                    len = 2;
                }
                direction = 1;
            } else {
                len = 1;
                direction = 0;
            }
            res = max(len, res);
        }
        return res;
    }
};