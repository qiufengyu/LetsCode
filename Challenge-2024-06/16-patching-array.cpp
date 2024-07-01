#include "../header.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int sz = nums.size();
        long mx = 1L;
        int index = 0, res = 0;
        while (mx <= n) {
            if (index < sz && nums[index] <= mx) {
                mx += nums[index];
                index++;
            } else {
                res++;
                mx += mx;
            }
        }
        return res;
    }
};