#include "../header.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, res = 0;
        int i = 0, j = 0, n = nums.size();
        while (i < n && j < n) {
            if (st.count(nums[j]) == 0) {
                sum += nums[j];
                res = max(sum, res);
                st.insert(nums[j]);
                ++j;
            } else {
                sum = sum - nums[i];
                st.erase(nums[i]);
                ++i;
            }
        }
        return res;
    }
};