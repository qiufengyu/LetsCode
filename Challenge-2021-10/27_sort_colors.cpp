#include "../header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0, 0, 0};
        for (auto const& i: nums) {
            ++counts[i];
        }
        int i = 0;
        for ( ; i < counts[0]; ++i) {
            nums[i] = 0;
        }
        for ( ; i < counts[0] + counts[1]; ++i) {
            nums[i] = 1;
        }
        for ( ; i < nums.size(); ++i) {
            nums[i] = 2;
        }
    }
};
