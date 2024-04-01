#include "../header.h"

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int start = 0, end = 0, n = nums.size(), res = 0;
        while (end < n) {
            int x = nums[end];
            mp[x]++;
            while (mp[x] > k) {
                mp[nums[start]]--;
                start++;
            }
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};