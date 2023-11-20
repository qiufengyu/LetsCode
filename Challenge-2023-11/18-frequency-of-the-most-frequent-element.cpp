#include "../header.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, res = 0;
        long long sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            if ((long)(r - l + 1) * nums[r] - sum > k) {
                sum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};