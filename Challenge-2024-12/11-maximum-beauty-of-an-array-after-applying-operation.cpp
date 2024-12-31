#include "../header.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int mx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        int count = 0, res = 0;
        int l = mn, r = mn;
        while (r <= mx) {
            count += mp[r];
            while (r - l > 2 * k) {
                count -= mp[l];
                l++;
            }
            r++;
            res = max(res, count);
        }
        return res;
    }
};