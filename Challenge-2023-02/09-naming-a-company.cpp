#include "../header.h"

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        vector<unordered_set<string>> v(26);
        for (auto const& idea: ideas) {
            v[idea[0] - 'a'].insert(idea.substr(1));
        }
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                unordered_set<string> tmp;
                tmp.insert(v[i].begin(), v[i].end());
                tmp.insert(v[j].begin(), v[j].end());
                res += (tmp.size() - v[i].size()) * (tmp.size() - v[j].size());
            }
        }
        return res;
    }
};