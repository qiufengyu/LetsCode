#include "../header.h"

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&m](char const& c1, char const& c2) -> bool {
            if (m.count(c1) && m.count(c2)) {
                return m[c1] < m[c2];
            } else if (m.count(c1)) {
                return true;
            }
            return false;
        });
        return s;
    }
};