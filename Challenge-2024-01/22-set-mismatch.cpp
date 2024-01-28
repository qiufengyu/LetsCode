#include "../header.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // math: get sum and sum of square
        int n = nums.size();
        int eSum = n * (n + 1) / 2;
        long long eSum2 = n * (n + 1) * (long long)(2 * n + 1) / 6;
        int sum = 0;
        long long sum2 = 0LL;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum2 += ((long long)nums[i] * nums[i]);
        }
        long long diff = eSum - sum, diff2 = eSum2 - sum2;
        long mPlusd = diff2 / diff;
        long mMinusd = diff;
        return {(int)((mPlusd - mMinusd) / 2), int((mPlusd + mMinusd) / 2)};
        // int n = nums.size();
        // int eSum = n * (n + 1) / 2;
        // set<int> s;
        // int sum = 0, dup = -1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (s.count(nums[i])) {
        //         dup = nums[i];
        //     }
        //     s.insert(nums[i]);
        //     sum += nums[i];
        // }
        // int miss = eSum - sum + dup;
        // return {dup, miss};
    }
};