#include "../header.h"

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        vector<vector<int>> ans;
        vector<int> a1, a2;
        for (int i = 0; i < matches.size(); ++i) {
            auto mt = matches[i];
            if (m.count(mt[0]) == 0) {
                m[mt[0]] = 0;
            }
            if (m.count(mt[1]) == 0) {
                m[mt[1]] = 1;
            } else {
                ++m[mt[1]];
            }
        }
        for (auto const& p: m) {
            if (p.second == 0) {
                a1.push_back(p.first);
            } else if (p.second == 1) {
                a2.push_back(p.first);
            }
        }
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};