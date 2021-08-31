#include "../header.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxNum = 1; // if n = MAX_INT then maxNum may overflow
        int res = 0;
        int i = 0;
        while (maxNum <= n) {
            if (i < nums.size() && nums[i] <= maxNum) {
                maxNum += nums[i];
                i++;
            } else {
                maxNum += maxNum;
                ++res;
            }
        }
        return res;
    }
};