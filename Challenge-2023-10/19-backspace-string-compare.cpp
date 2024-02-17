#include "../header.h"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = backspace(s);
        t = backspace(t);
        return s == t;
    }

    string backspace(string s) {
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                s[idx++] = s[i];
            } else {
                idx = max(idx-1, 0);
            }
        }
        return s.substr(0, idx);
    }
};