#include "../header.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0LL, res = 0LL;
        int unique = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) {
                unique++;
            }
        }
        if (unique == k) {
            res = max(sum, res);
        }
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i-k];
            sum += nums[i];
            mp[nums[i-k]]--;
            if (mp[nums[i-k]] == 0) {
                unique--;
            }
            mp[nums[i]]++;
            if (mp[nums[i]] == 1) {
                unique++;
            }
            if (unique == k) {
                res = max(sum, res);
            }
        }
        return res;
    }
};