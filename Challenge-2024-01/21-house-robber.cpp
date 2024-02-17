#include "../header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0, r2 = nums[0], t = r2; // nums.length >= 1
        for (int i = 1; i < nums.size(); ++i) {
            t = r2;
            r2 = r1 + nums[i];
            r1 = max(r1, t);
        }
        return max(r1, r2);
    }
};