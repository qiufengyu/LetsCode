#include "../header.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0) {
            return -1;
        }
        if (target == 0) {
            return n;
        }
        int start = 0, current = 0, len = -1;
        for (int i = 0; i < n; ++i) {
            if (current < target) {
                current += nums[i];
            }
            while (current >= target) {
                if (current == target) {
                    len = max(len, i - start + 1);
                }
                current -= nums[start];
                ++start;
            }
        }
        return len == -1 ? -1 : n - len;
    }

    void helper(vector<int>& nums, int i, int j, int x, const int n, int& res) {
        if (i <= j && i < n && j >= 0) {
            if (nums[i] == x || nums[j] == x) {
                if (res < 0) {
                    res = n - (j - i);
                } else {
                    res = min(res, n - (j - i));
                }
            } else {
                if (nums[i] < x) {
                    helper(nums, i + 1, j, x - nums[i], n, res);
                }
                if (nums[j] < x) {
                    helper(nums, i, j - 1, x - nums[j], n, res);
                }
            }
        }
    }
};