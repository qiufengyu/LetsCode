#include "../header.h"

class Solution {
public:
    int appendCharacters(string s, string t) {
        int si = 0, ti = 0, matched = 0;
        while (si < s.size() && ti < t.size()) {
            if (s[si] == t[ti]) {
                si++;
                ti++;
                matched++;
            } else {
                si++;
            }
        }
        return t.size() - matched;
    }
};