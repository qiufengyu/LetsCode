#include "../header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = r1;
            r1 = max(r1, r2 + nums[i]);
            r2 = temp;
        }
        return max(r1, r2);
    }
};
