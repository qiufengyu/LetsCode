#include "../header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size();
        int l = 0, r = width - 1, h = 0;
        int res = 0;
        while (l < r) {
            h = min(height[l], height[r]);
            res = max(res, h * (r-l));
            if (height[l] > height[r]) {
                --r;
            } else {
                ++l;
            }
        }
        return res;
    }
};