#include "../header.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // vector<int> opt (0, nums.size());
        int prod = 1;
        int leftIndex = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while (leftIndex <= i && prod >= k) {
                prod /= nums[leftIndex];
                leftIndex++;
            }
            ans += i - leftIndex + 1;
            // opt[i] = leftIndex;
        }
        return ans;
    }
};