#include "../header.h"

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        for (int i = 0; i < s.size(); i++) {
            int idx = i;
            while (idx < s.size() && s[i] == s[idx]) {
                mp[s.substr(i, (idx - i + 1))]++;
                idx++;
            }
        }
        int maxLen = 0;
        for (auto const &[k, c]: mp) {
            if (c >= 3) {
                maxLen = max(maxLen, (int)k.size());
            }
        }
        return maxLen == 0 ? -1 : maxLen;
    }
};