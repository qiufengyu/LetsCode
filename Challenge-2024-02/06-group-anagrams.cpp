#include "../header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto const& s: strs) {
            string t{s};
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto const& p: m) {
            res.push_back(p.second);
        }
        return res;
    }
};