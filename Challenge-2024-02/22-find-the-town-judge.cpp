#include "../header.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            return 1;
        }
        unordered_map<int, unordered_set<int>> t, it;
        for (auto const& tt: trust) {
            t[tt[0]].insert(tt[1]);
            it[tt[1]].insert(tt[0]);
        }
        for (auto const& p: it) {
            if (p.second.size() == n - 1 && t.count(p.first) == 0) {
                return p.first;
            }
        }
        return -1;
    }
};