#include "../header.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mv;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> v = nums[i];
            for (int j = 0; j < v.size(); j++) {
                mv[i+j].insert(mv[i+j].begin(), v[j]);
            }
        }
        vector<int> res;
        for (auto const& p: mv) {
            for (int i = 0; i < p.second.size(); i++) {
                res.push_back(p.second[i]);
            }
        }
        return res;
    }
};