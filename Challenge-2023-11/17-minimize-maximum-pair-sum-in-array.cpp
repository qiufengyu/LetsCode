#include "../header.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // use shell-sort like idea to count frequencies of all numbers -> O(n)
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int res = nums[l] + nums[r];
        while (l < r) {
            res = max(res, nums[l] + nums[r]);
            l++;
            r--;
        }
        return res;
    }
};