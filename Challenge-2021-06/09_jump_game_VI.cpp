#include "../header.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int res = nums[0];
      priority_queue<pair<int, int>> pq;
      pq.emplace(nums[0], 0);
      for (int i = 1; i < nums.size(); ++i) {
        while (i - pq.top().second > k) {
          pq.pop();
        }
        res = pq.top().first + nums[i];
        pq.emplace(res, i);
      }
      return res;
    }
};