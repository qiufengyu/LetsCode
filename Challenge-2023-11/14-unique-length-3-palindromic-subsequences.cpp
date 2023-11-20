#include "../header.h"

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> startIndex, endIndex;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (startIndex.count(s[i])) {
                endIndex[s[i]] = i;
            } else {
                startIndex[s[i]] = i;
            }
        }
        for (auto const& p: startIndex) {
            if (endIndex.count(p.first) != 0 && endIndex[p.first] > 1 + p.second) {
                unordered_set<char> us;
                for (int i = p.second + 1; i < endIndex[p.first]; i++) {
                    us.insert(s[i]);
                }
                res += us.size();
            }
        }
        return res;
    }
};