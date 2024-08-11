#include "../header.h"

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int length = accumulate(nums.begin(), nums.end(), 0);
        int current = 0;
        for (int j = n - length; j < n; j++) {
            current += nums[j];
        }
        int count = current;
        for (int i = 0; i < n; i++) {
            int start = (i - length + n) % n;
            current -= nums[start];
            current += nums[i];
            count = max(current, count);
        }
        return length - count;
    }
};