#include "../header.h"

int const M = 1000000007;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1;
        int res = 0;
        vector<int> powers(n, 1);
        for (int i = 1; i < n; ++i) {
            powers[i] = (powers[i-1] * 2) % M;
        }
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + powers[r-l]) % M;
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};