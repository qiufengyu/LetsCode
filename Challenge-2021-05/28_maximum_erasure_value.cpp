#include "../header.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int i = 0, j = 0;
      unordered_set<int> m;
      int n = nums.size();
      int sum = 0, maxSum = 0;
      while (j < n) {
        if (m.find(nums[j]) == m.end()) {
          sum += nums[j];
          maxSum = max(sum, maxSum);
          m.insert(nums[j]);
          ++j;
          continue;
        }
        // has duplicate number
        while (m.find(nums[j]) != m.end()) {
          m.erase(nums[i]);
          sum -= nums[i];
          ++i;
        }
      }
      return maxSum;        
    }
};