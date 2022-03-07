#include "../header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        int i = 0, j = 0;
        while (i < sl && j < tl) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == sl;
    }
};
