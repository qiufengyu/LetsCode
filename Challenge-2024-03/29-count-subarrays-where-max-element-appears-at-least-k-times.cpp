#include "../header.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int start = 0, end = 0, count = 0, n = nums.size(), index = -1;
        long long res = 0LL;
        while (end < n) {
            if (nums[end] == mx) {
                count++;
            }
            while (count >= k) {
                if (nums[start] == mx) {
                    index = start;
                    count--;
                }
                start++;
            }
            if (index >= 0) {
                res += (1 + index);
            }
            end++;
        }
        return res;
    }
};