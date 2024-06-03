#include "../header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        vector<int> current;
        for (int i = 0; i < nums.size(); i++) {
            current.push_back(nums[i]);
            res.push_back(current);
            helper(nums, i, current, res);
            current.pop_back();
        }
        return res;
    }

    void helper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& res) {
        for (int i = index + 1; i < nums.size(); i++) {
            current.push_back(nums[i]);
            res.push_back(current);
            helper(nums, i , current, res);
            current.pop_back();
        }
    }
};