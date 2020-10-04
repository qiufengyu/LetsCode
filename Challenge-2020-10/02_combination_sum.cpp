#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(candidates, target, 0, temp, res);
        return res;
    }

    void helper(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>> &res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, temp, res);
            temp.pop_back();
        }
    }
};