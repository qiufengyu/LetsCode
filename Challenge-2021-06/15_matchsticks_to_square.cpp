#include "../header.h"

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
          return false;
        }
        // sort big -> small can help prune
        sort(matchsticks.begin(), matchsticks.end(), [](const int& a, const int& b) -> bool { return a > b; });
        int sz = matchsticks.size();
        vector<int> sums(4, 0);
        return helper(matchsticks, 0, sz, sums, sum / 4);
    }

    bool helper(vector<int>& matchsticks, int i, const int size, vector<int>& sums, const int target) {
      if (i >= size) {
        return sums[0] == target && sums[1] == target && sums[2] == target;
      }
      for (int j = 0; j < 4; ++j) {
        if (sums[j] + matchsticks[i] > target) {
          continue;
        }
        sums[j] += matchsticks[i];
        if (helper(matchsticks, i + 1, size, sums, target)) {
          return true;
        }
        sums[j] -= matchsticks[i];
      }
      return false;
    }
};
