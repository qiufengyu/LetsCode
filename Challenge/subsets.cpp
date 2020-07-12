#include "header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        helper(nums, res, current, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& current, int pos) {
        res.push_back(current);
        for (int i = pos; i < nums.size(); i++) {
            current.push_back(nums[i]);
            helper(nums, res, current, i+1);
            current.pop_back();
        }
    }
};