#include "../header.h"

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int res = 0;
        long long current = 0LL;
        for (int i = 0; i < nums.size() - 1; i++) {
            current += nums[i];
            if (current >= sum - current) {
                res++;
            }
        }
        return res;
    }
};