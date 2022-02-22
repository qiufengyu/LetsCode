#include "../header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int const& i: nums) {
            res = res ^ i;
        }
        return res;
    }
};