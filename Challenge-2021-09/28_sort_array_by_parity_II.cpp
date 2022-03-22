#include "../header.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 0, even = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (i % 2 == 0) {
                if (nums[i] % 2 != 0) {
                    even = i;
                    while (even < sz && nums[even] % 2 != 0) even++;
                    // swap nums[i] && nums[even]
                    swap(nums[i], nums[even]);
                }
            } else {
                if (nums[i] % 2 == 0) {
                    odd = i;
                    while (odd < sz && nums[odd] %2 == 0) odd++;
                    swap(nums[i], nums[odd]);
                }
            }
        }
        return nums;
    }
};