#include "../header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), ps = p.size();
        vector<int> res;
        if (ss < ps) {
            return {};
        }
        vector<int> sv(26, 0), pv(26, 0);
        for (int i = 0; i < ps; ++i) {
            pv[p[i] - 'a'] += 1;
            sv[s[i] - 'a'] += 1;
        }
        for (int i = ps; i <= ss; ++i) {
            if (pv[s[i - ps] - 'a'] > 0) {
                if (pv == sv) {
                    res.push_back(i - ps);
                }
            }
            if (i < ss) {
                sv[s[i] - 'a'] += 1;
                sv[s[i - ps] - 'a'] -= 1;
            }
        }
        return res;
    }
};