#include "../header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n > 0) {
            sort(nums.begin(), nums.end());
            vector<bool> used(n, false);
            vector<int> current;
            dfs(nums, used, current, res);
        }
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& res) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                // skip duplicates
                if (i > 0 && nums[i-1] == nums[i] && !used[i-1]) {
                    continue;
                }
                used[i] = true;
                current.push_back(nums[i]);
                dfs(nums, used, current, res);
                used[i] = false;
                current.pop_back();

            }
        }
    }
};