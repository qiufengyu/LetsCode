#include "../header.h"

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // get ceil of average
            res = max(res, (i + sum) / (i+1));
        }
        return res;
    }
};