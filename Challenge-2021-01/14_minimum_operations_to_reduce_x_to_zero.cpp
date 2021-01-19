#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int S = 0;
      unordered_map<int, int> m;
      m[0] = 0;
      for (int i = 0; i < nums.size(); i++) {
        S += nums[i];
        m[S] = i+1; // please note that nums[i] > 0
      }
      int K = S - x;
      if (K < 0) {
        return -1;
      }
      // The problem is converted to find a longest subarray with sum equals K;
      int ans = INT_MIN;
      for (auto const& e: m) {
        if (m.count(K + e.first)) {
          ans = max(ans, m[K+e.first] - e.second);
        }
      }
      if (ans == INT_MIN) {
        return -1;
      } else {
        return nums.size() - ans;
      }      
    }
};