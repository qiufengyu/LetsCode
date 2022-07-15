#include "../header.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mh = 0, mw = 0;
        for (int i = 0; i < horizontalCuts.size() - 1; ++i) {
            mh = max(mh, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for (int i = 0; i < verticalCuts.size() - 1; ++i) {
            mw = max(mw, verticalCuts[i+1] - verticalCuts[i]);
        }
        return ((long) mh * mw) % 1000000007;
    }
};