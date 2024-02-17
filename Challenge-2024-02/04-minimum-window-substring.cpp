#include "../header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tm;
        for (int i = 0; i < t.size(); i++) {
            tm[t[i]]++;
        }
        int l = 0, r = 0, start = 0, minLen = INT_MAX;
        int count = t.size();
        while (r < s.size()) {
            if (tm[s[r]] > 0) {                
                count--;
            }
            tm[s[r]]--;
            r++;
            while (count == 0) {
                if (r - l < minLen) {
                    start = l;
                    minLen = r - l;
                }
                tm[s[l]]++;
                if (tm[s[l]] > 0) {
                    count++;
                }
                l++;
            }
        }
        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};