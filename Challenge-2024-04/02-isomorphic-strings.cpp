#include "../header.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s2t.count(s[i])) {
                if (t2s.count(t[i])) {
                    if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if (t2s.count(t[i])){
                return false;
            } else {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
        }
        return true;
    }
};