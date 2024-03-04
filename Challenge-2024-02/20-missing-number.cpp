#include "../header.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        return expectedSum - sum;   
    }
};