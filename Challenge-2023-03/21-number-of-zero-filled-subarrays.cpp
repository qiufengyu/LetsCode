#include "../header.h"

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0LL;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++count;
            } else {
                res += ((long long)(count) * (long long)(count + 1) / 2);
                count = 0;
            }
        }
        if (count > 0) {
            res += ((long long)(count) * (long long)(count + 1) / 2);
        }
        return res;
    }
};