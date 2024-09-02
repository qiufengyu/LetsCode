#include "../header.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int mn1 = 10001, mn2 = 100001, mx1 = -10001, mx2 = -10001;
        int mnIndex = -1, mxIndex = -1;
        for (int i = 0; i < n; i++) {
            int la = arrays[i].size();
            int mn = arrays[i][0], mx = arrays[i][la-1];
            if (mn < mn1) {
                mn2 = mn1;
                mn1 = mn;
                mnIndex = i;
            } else if (mn < mn2) {
                mn2 = mn;
            }
            if (mx > mx1) {
                mx2 = mx1;
                mx1 = mx;
                mxIndex = i;
            } else if (mx > mx2) {
                mx2 = mx;
            }
        }
        if (mnIndex == mxIndex) {
            return max(mx1-mn2, mx2-mn1);
        }
        return mx1 - mn1;
    }
};