#include "../header.h"

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) {
                m[s[i]] = -1;
            } else {
                m[s[i]] = i;
            }
        }
        int res = INT_MAX;
        for (auto const& p: m) {
            if (p.second != -1) {
                res = min(res, p.second);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};