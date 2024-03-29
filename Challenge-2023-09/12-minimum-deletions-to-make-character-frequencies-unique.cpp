#include "../header.h"

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnt;
        unordered_map<int, char> m;
        int res = 0;
        for (auto const& c: s) {
            ++cnt[c];
        }
        for (auto const& p: cnt) {
            if (!m.count(p.second)) {
                m[p.second] = p.first;
            } else {
                int t = p.second - 1;
                while (t > 0 && m.count(t)) {
                    t--;
                }
                if (t > 0) {
                    m[t] = p.first;
                }
                res += (p.second - t);
            }
        }
        return res;
    }
};