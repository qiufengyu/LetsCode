#include "../header.h"

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> wm, lm;
        for (auto const& m: matches) {
            ++wm[m[0]];
            ++lm[m[1]];
        }
        vector<int> wv, lv;
        for (auto const& p: wm) {
            if (lm.count(p.first) == 0) {
                wv.push_back(p.first);
            }
        }
        for (auto const& p: lm) {
            if (p.second == 1) {
                lv.push_back(p.first);
            }
        }
        return {wv, lv};
    }
};