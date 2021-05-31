#include "../header.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        auto minmax = std::minmax_element(nums.begin(), nums.end());
        int range = *minmax.second - *minmax.first;
        int binSize = range / n + 1;
        // normally we don't need n bins
        vector<int> minVals(n, INT_MAX), maxVals(n, INT_MIN);
        for (int num: nums) {
          int index = (num - *minmax.first) / binSize;
          minVals[index] = min(minVals[index], num);
          maxVals[index] = max(maxVals[index], num);
        }
        int maxGap = 0;
        int prevMax = maxVals[0];
        for (int i = 1; i < n; ++i) {
          if (minVals[i] != INT_MAX) {
            maxGap = max(maxGap, minVals[i] - prevMax);
            prevMax = maxVals[i];
          }
        }
        return maxGap;
    }
};