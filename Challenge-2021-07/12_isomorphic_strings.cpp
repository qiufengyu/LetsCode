#include "../header.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> im;
        int s1 = s.size(), s2 = t.size();
        if (s1 != s2) {
            return false;
        }
        for (int i = 0; i < s1; ++i) {
            if (m.count(s[i]) || im.count(t[i])) {
                if (m[s[i]] != t[i] || im[t[i]] != s[i]) {
                    return false;
                }
            } else {
                m[s[i]] = t[i];
                im[t[i]] = s[i];
            }
        }
        return true;
    }
};
