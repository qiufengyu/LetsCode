#include "../header.h"

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            n = max(n, m[nums[i]]);
        }
        vector<vector<int>> res(n, vector<int>());
        for (auto const& p: m) {
            for (int i = 0; i < p.second; i++) {
                res[i].push_back(p.first);
            }
        }
        return res;
    }
};