#include "../header.h"

class Solution {
    unordered_map<char, int> sCount, tCount;
public:
    bool check() {
        for (auto const [c, i]: tCount) {
            if (sCount[c] < i) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (auto const& c: t) {
            ++tCount[c];
        }
        int l = 0, r = 0;
        int len = INT_MAX, resL = -1;
        while (r < s.size()) {            
            ++sCount[s[r]];            
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    resL = l;
                }
                if (sCount.count(s[l]) > 0) {
                    --sCount[s[l]];
                }
                ++l;
            }
            ++r;
        }
        if (resL == -1) {
            return "";
        }
        return s.substr(resL, len);        
    }
};