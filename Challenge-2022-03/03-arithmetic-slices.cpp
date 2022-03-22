#include "../header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, l = 0, sz = nums.size();
        if (sz < 3) {
            return 0;
        }
        for (int i = 2; i < sz; ++i) {
            if (nums[i] + nums[i-2] == (2 * nums[i-1])) {
                ++l;
                res += l;
            } else {
                l = 0;
            }
        }
        return res;
    }
};
