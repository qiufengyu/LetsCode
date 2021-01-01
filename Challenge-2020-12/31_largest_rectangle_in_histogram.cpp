#include "../header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int length = heights.size();
        for (int i = 0; i < length; i++) {
            if (i + 1 < length && heights[i] <= heights[i+1]) {
                continue;
            }
            int minHeight = heights[i];
            for (int j = i; j >= 0; j--) {
                minHeight = min(minHeight, heights[j]);
                res = max(res, minHeight * (i - j + 1));
            }
        }
        return res;
    }
};
