#include "../header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        vector<map<long, int>> count(sz);
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                long delta = (long)nums[i] - (long)nums[j];
                int temp = 0;
                if (count[j].count(delta)) {
                    temp = count[j][delta];
                }
                count[i][delta] += (temp + 1);
                res += temp;
            }
        }
        return res;
    }
};