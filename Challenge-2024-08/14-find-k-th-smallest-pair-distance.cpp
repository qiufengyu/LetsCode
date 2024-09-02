#include "../header.h"

class Solution {
    int countPairs(vector<int>& nums, const int n, int distance) {
        int count = 0, j = 0;
        for (int i = 0; i < n; i++) {
            j = i;
            while (j < n && nums[j] - nums[i] <= distance) {
                j++;
            }
            count += (j - i - 1);
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = nums[n-1] - nums[0];
        while (l < h) {
            int m = l + (h - l) / 2;
            if (countPairs(nums, n, m) < k) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
};