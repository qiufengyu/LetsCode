#include "../header.h"

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), res = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for (auto const& p: mp) {
            res += (p.second / 2);
        }
        if (res * 2 < n) {
            return res * 2 + 1;
        }
        return res * 2;
    }
};