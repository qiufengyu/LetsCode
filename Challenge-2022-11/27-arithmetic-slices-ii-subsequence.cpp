#include "../header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<map<long, int>> v(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - (long)nums[j];
                int temp = 0;
                if (v[j].count(diff)) {
                    temp = v[j][diff];
                }
                v[i][diff] += (temp + 1);
                res += temp;
            }
        }
        return res;
    }
};