#include "../header.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return b[1] < a[1];
            } else {
                return a[0] < b[0];
            }
        });
        int n = envelopes.size();
        vector<int> dp;
        int res = 0;
        for (const vector<int>& e: envelopes) {
            int height = e[1];
           auto it = lower_bound(dp.begin(), dp.end(), height);
           if (it == dp.end()) {
               dp.push_back(height);
           } else  {
               *it = height;
           }
        }
        return dp.size();
    }
};