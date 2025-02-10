#include "../header.h"

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int res = 0;
        for (auto const& [c, n]: mp) {
            if ((n % 2) == 1) {
                res += 1;
            } else {
                res += 2;
            }
        }
        return res;
    }
};