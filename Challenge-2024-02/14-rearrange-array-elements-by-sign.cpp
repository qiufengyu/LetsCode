#include "../header.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), oddIndex = 0, evenIndex = 1;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                res[oddIndex] = nums[i];
                oddIndex += 2;
            } else {
                res[evenIndex] = nums[i];
                evenIndex += 2;
            }
        }
        return res;
    }
};