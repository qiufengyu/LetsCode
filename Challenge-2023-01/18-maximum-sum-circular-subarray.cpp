#include "../header.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN, maxCurrent = 0, minSum = INT_MAX, minCurrent = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];            
            maxCurrent = max(nums[i], nums[i] + maxCurrent);
            maxSum = max(maxSum, maxCurrent);
            minCurrent = min(nums[i], nums[i] + minCurrent);
            minSum = min(minSum, minCurrent);
        }
        if (maxSum > 0) {
            return max(maxSum, sum - minSum);
        }
        return maxSum;
    }
};