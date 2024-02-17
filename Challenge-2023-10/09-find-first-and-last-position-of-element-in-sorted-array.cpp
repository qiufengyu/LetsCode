#include "../header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int l = 0, r = n - 1, m = l + (r - l) / 2;
        int start = -1, end = -1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        start = nums[r] == target ? r : -1;
        if (start == -1) {
            return {-1, -1};
        }
        end = start;
        l = start;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (nums[l] == target) {
            end = l;
        } else {
            end = max(start, l - 1);
        }
        return {start, end};
    }
};