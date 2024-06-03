#include "../header.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorAll ^= nums[i];
        }
        int pos = 0;
        while ((xorAll & (1 << pos)) == 0) {
            pos++;
        }
        int r1 = 0, r2 = 0, pivot = (1 << pos);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & pivot) {
                r1 ^= nums[i];
            } else {
                r2 ^= nums[i];
            }
        }
        return {r1, r2};
    }
};