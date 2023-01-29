#include "../header.h"

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> remainder(k, 0);
        remainder[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + (nums[i] % k) + k) % k;
            res += remainder[sum];
            ++remainder[sum];
        }
        return res;
    }
};