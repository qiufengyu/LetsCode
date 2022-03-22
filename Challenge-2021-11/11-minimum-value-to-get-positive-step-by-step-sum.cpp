#include "../header.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1, sum = 0;
        for (auto const& n: nums) {
            sum += n;
            if (res + sum <= 0) {
                res = 1 - sum;
            }
        }
        return res;
    }
};