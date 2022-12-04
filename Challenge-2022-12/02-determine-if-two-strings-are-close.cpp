#include "../header.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        int n = word1.size();
        unordered_map<char, int> c1, c2;
        for (int i = 0; i < n; ++i) {
            ++c1[word1[i]];
            ++c2[word2[i]];
        }
        unordered_map<int, int> ic1, ic2;
        for (auto const& p: c1) {
            ++ic1[p.second];
            if (c2.count(p.first) == 0) {
                return false;
            }
        }
        for (auto const& p: c2) {
            ++ic2[p.second];            
        }
        for (auto const& p: ic1) {
            if (ic2.count(p.first) == 0 || ic2[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
};