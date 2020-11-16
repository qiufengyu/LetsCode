#include "../header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        dfs(nums, res, used, current);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<bool>& used, vector<int>& current) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            dfs(nums, res, used, current);
            current.pop_back();
            used[i] = false;
        }
    }
};