#include "../header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int leftMax = height[start], rightMax = height[end];
        int res = 0;
        while (start < end) {
          int w = end - start;
          leftMax = height[start];
          rightMax = height[end];
          res = max(res, w * min(leftMax, rightMax));
          if (leftMax < rightMax) {
            ++start;
          } else {
            --end;
          }
        }
        return res;
    }
};
