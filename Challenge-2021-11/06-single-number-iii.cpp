#include "../header.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        int p1 = 0, p2 = 0;
        for (auto const& i: nums) {
            if (diff & i) {
                p1 ^= i;
            } else {
                p2 ^= i;
            }
        }
        return {p1, p2};
    }
};