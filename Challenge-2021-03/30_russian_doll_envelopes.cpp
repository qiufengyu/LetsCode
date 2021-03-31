#include "../header.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int sz = envelopes.size();
        if (sz == 0) {
          return 0;
        }
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
          if (a[0] == b[0]) {
            return a[1] > b[1];
          }
          return a[0] < b[0]; 
        });
        // width is increasing, considering height only -> LIS by binary search
        vector<int> dp;
        for (int i = 0; i < sz; ++i) {
          int second = envelopes[i][1];
          auto it = lower_bound(dp.begin(), dp.end(), second);
          if (it == dp.end()) {
            dp.push_back(second);
          } else {
            *it = second;
          }
        }
        return dp.size();
    }
};