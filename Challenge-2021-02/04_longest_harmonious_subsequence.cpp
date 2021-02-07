#include "../header.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
      int res = 0;
      unordered_map<int, int> m;
      for (auto n: nums) {
        ++m[n];
      }
      for (auto e: m) {
        if (m.count(e.first+1)) {
          res = max(res, m[e.first+1] + e.second);
        }
      }
      return res;
    }
};