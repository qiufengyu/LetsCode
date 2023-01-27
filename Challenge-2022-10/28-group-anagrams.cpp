#include "../header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string const& str: strs) {
            string t{str};
            sort(t.begin(), t.end());
            if (m.count(t)) {
                m[t].push_back(str);
            } else {
                m[t] = {str};
            }
        }
        for (auto const& p: m) {
            res.push_back(p.second);
        }
        return res;
    }
};