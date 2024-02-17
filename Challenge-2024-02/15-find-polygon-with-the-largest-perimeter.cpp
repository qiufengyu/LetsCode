#include "../header.h"

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0LL;
        long long res = -1LL;
        for (int i = 0; i < n; i++) {
            if (i >= 2 && nums[i] < sum) {
                res = nums[i] + sum;
            }
            sum += nums[i];
        }
        return res;
    }
};