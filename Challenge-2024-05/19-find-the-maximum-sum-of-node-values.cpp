#include "../header.h"

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        long long totalDiff = 0LL, diff = 0LL;
        int positive = 0;
        long long minAbsDiff = LONG_MAX;
        for (int i = 0; i < nums.size(); i++) {
            diff = (nums[i] ^ k) - nums[i];
            if (diff > 0) {
                totalDiff += diff;
                positive++;
            }
            minAbsDiff = min(minAbsDiff, abs(diff));
        }
        if (positive % 2 == 1) {
            totalDiff -= minAbsDiff;
        }
        return totalDiff + res;
    }
};