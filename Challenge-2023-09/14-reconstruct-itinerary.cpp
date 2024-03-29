#include "../header.h"


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto const& ticket: tickets) {
            m[ticket[0]].insert(ticket[1]);
        }
        dfs(m, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, multiset<string>>& m, vector<string>& res, string const& ap) {
        while (!m[ap].empty()) {
            string n = *m[ap].begin();
            m[ap].erase(m[ap].begin());
            dfs(m, res, n);
        }
        res.push_back(ap);
    }
};