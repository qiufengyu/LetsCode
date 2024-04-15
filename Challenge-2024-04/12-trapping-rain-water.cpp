#include "../header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMx = height[left], rightMx = height[right];
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                leftMx = max(leftMx, height[left]);
                res += leftMx - height[left];
                left++;
            } else {
                rightMx = max(rightMx, height[right]);
                res += rightMx - height[right];
                right--;
            }
        }
        return res;
    }
};