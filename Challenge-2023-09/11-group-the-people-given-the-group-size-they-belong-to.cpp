#include "../header.h"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> m;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int gs = groupSizes[i];
            if (m.count(gs)) {
                m[gs].push_back(i);
            } else {
                m[gs] = {i};
            }
        }
        for (auto const& p: m) {
            int gs = p.first;
            vector<int> v = p.second;
            vector<int> group = {};
            for (int i = 0; i < v.size(); i++) {
                group.push_back(v[i]);
                if ((i + 1) % gs == 0) {
                    res.push_back(group);
                    group = {};
                }
            }
        }
        return res;
    }
};