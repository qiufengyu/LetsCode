#include "../header.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        vector<int> current;
        for (int i = 0; i < n - 1; ++i) {
            current.push_back(nums[i]);
            dfs(nums, res, i, current);
            current.pop_back();
        }
        vector<vector<int>> r(res.begin(), res.end());
        return r;
    }

    void dfs(vector<int>& nums, set<vector<int>>& res, int index, vector<int>& current) {
        int end = current.back();
        for (int j = index + 1; j < nums.size(); ++j) {
            if (nums[j] >= end) {
                current.push_back(nums[j]);
                res.insert(current);
                dfs(nums, res, j, current);
                current.pop_back();
            }
        }
    }
};