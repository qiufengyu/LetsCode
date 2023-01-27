#include "../header.h"

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        // vector<int> preSum(n, 0);
        // preSum[0] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     preSum[i] = preSum[i-1] + nums[i];
        // }
        long prev = 0, last = sum;
        long prevAvg = 0, lastAvg = 0;
        long diff = INT_MAX, res = 0;
        for (int i = 0; i < n; ++i) {
            prev += nums[i];
            last -= nums[i];
            prevAvg = prev / (1 + i);
            lastAvg = (i == n - 1 ? 0 : last / (n - i - 1));
            if (abs(prevAvg - lastAvg) < diff) {
                res = i;
                diff = abs(prevAvg - lastAvg);
            }
        }
        return res;
    }
};