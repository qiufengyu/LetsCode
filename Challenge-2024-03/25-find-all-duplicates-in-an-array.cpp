#include "../header.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[nums[i] - 1]) {
                res.push_back(nums[i]);
            } else {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return res;
    }
};