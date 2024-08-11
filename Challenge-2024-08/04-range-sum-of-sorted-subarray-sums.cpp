#include "../header.h"

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sums(n*(n+1)/2, 0), preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            sums[k++] = preSum[i];
            for (int j = 0; j < i; j++) {
                sums[k++] = (preSum[i] - preSum[j]);
            }
        }
        sort(sums.begin(), sums.end());
        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res = ((int)(sums[i] % 1000000007) + res) % 1000000007;
        }
        return res;
    }
};