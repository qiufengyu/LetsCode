#include "../header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1, i = 0, n = s.size(), res = 0;
        unordered_map<char, int> m;
        while (i < n) {
            if (m.count(s[i]) && m[s[i]] > start) {
                start = m[s[i]];
            }
            m[s[i]] = i;            
            res = max(res, i - start);
            ++i;
        }
        return res;
    }
};