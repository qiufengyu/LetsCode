#include "../header.h"

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for (char &c: s) {
            if (c == '#') {
                if (ss.size() > 0) {
                    ss.pop_back();
                }
            } else {
                ss.push_back(c);
            }
        };
        for (char &c: t) {
            if (c == '#') {
                if (tt.size() > 0) {
                    tt.pop_back();
                }
            } else {
                tt.push_back(c);
            }
        };
        return ss == tt;
    }
};