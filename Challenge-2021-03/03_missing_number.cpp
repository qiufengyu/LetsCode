#include "../header.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        size_t sum = (n + 1) * n / 2;
        for (auto &x: nums) {
            sum -= x;
        }
        return (int)sum;
    }
};
