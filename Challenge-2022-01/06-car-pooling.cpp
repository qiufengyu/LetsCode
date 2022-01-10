#include "../header.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cap[1001];
        memset(cap, 0, sizeof(cap));
        for (vector<int> const& trip: trips) {
            cap[trip[1]] += trip[0];
            cap[trip[2]] -= trip[0];
        }
        int c = 0;
        for (int i = 0; i < 1001; ++i) {
            c += cap[i];
            if (c > capacity) {
                return false;
            }
        }
        return true;
    }
};
