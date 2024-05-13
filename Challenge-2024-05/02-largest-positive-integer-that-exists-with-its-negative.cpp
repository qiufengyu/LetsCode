#include "../header.h"

class Solution {
    Solution() {
        ios::sync_with_stdio(false); 
        cin.tie(0);
    }
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start < end) {
            if (nums[end] == -nums[start]) {
                return nums[end];
            } else if (nums[end] > -nums[start]) {
                end--;
            } else {
                start++;
            }
        }
        return -1;
    }
};