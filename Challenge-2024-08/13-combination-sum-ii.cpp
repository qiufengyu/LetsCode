#include "../header.h"


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> current;
        vector<bool> used(n, false);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                used[i] = true;
                helper(candidates, used, current, res, i, target - candidates[i], n);
                current.pop_back();
                used[i] = false;
            }
        }
        unordered_set<string> us;
        vector<int> resIndex;
        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
            string s = "";
            for (int x: res[i]) {
                s += to_string(x);
                s += ",";
            }
            if (us.count(s) == 0) {
                us.insert(s);
                resIndex.push_back(i);
            }
        }
        vector<vector<int>> res1;
        for (int i = 0; i < resIndex.size(); i++) {
            res1.push_back(res[resIndex[i]]);
        }
        return res1;
    }

    void helper(vector<int>& candidates, vector<bool>& used, vector<int>& current, vector<vector<int>>& res, int index, int target, int const n) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        for (int i = index + 1; i < n; i++) {
            if (i > (index + 1) && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] <= target && (!used[i])) {
                current.push_back(candidates[i]);
                used[i] = true;
                helper(candidates, used, current, res, i, target - candidates[i], n);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};