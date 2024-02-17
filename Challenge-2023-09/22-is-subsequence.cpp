#include "../header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        int ti = 0, si = 0;
        while (si < sl) {
            if (ti >= tl) {
                return false;
            }
            while (ti < tl && s[si] != t[ti]) {
                ti++;
            }
            ti++;
            si++;
        }
        return ti <= tl;
    }
};