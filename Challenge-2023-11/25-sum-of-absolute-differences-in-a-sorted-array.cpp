#include "../header.h"

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0), sums(n, nums[0]);
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            int current = sums[i];
            int sumPrev = i > 0 ? sums[i-1] : 0;
            int sumLatt = sums[n-1] - sums[i];
            res[i] = (nums[i] * i - sumPrev) + (sumLatt - nums[i] * (n - i - 1));
        }
        return res;
    }
};